#include "list.h"

sem_t semaphore;

queue *initialiser() {
	queue *list = malloc(sizeof(*list));
	list->first = NULL; // pointe vers le premier élément de la liste
	list->last = NULL; // pointe vers le dernier élément de la liste

	return list;
}

void add_to_list(queue *list, int nvNombre, int numcase) {
	user_input *new_element = malloc(sizeof(*new_element)); // création du nouvel élément
//	if (list == NULL || new_element == NULL) {
//		exit(EXIT_FAILURE);
//	}
	new_element->autre_data = numcase;
	new_element->nombre = nvNombre; //affectation du numéro du nouvel élément
	new_element->next = NULL; //init du pointeur suivant

	if (list->first != NULL) /* La liste n'est pas vide */
	{

		/* On se positionne à la fin de la liste ici avec un while */
//        Element *elementActuel = list->first;
//        while (elementActuel->next != NULL)
//        {
//            elementActuel = elementActuel->next;
//        }
//        elementActuel->next = new_element;
		user_input *elementActuel = list->last; // on pointe le dernier élément de la liste actuelle qui sera l'avant-dernier
		elementActuel->next = new_element; // on fait pointer le pointeur de l'avant dernier vers le dernier
		list->last = new_element; // on affecte le nouvel élément comme étant le dernier

	} else /* La liste est vide, notre élément est le premier */
	{
		list->first = new_element; // ici le tout premier élément de la liste, c'est donc le premier et le dernier
		list->last = new_element;
	}
}

int delete_first_element(queue *list, user_input *element) {
//	if (list == NULL) {
//		exit(EXIT_FAILURE);
//	}

//	element = malloc(sizeof(*element)); //initialisation de la valeur retour pour affichage du num qui sera supprimé
	/* On vérifie s'il y a quelque chose à retirer */
	if (list->first == NULL) {
		return 0;
	}
	user_input *first_element = list->first; // sélection du premier élément
	memcpy(element, first_element, sizeof(user_input));
	//        Element *element = first_element; //saisie données élément de la liste
	//        element->nombre = first_element->nombre;
	//        element->autre_data = first_element->autre_data;
	list->first = first_element->next; //mise à jour du pointeur du premier élément
	free(first_element); //suppression du premier élément

	return 1;

}

void show_list(queue *list) {
//	if (list == NULL) {
//		exit(EXIT_FAILURE);
//	}

	user_input *element = list->first;

	while (element != NULL) {
		printf("%d ", element->nombre);
		element = element->next;
	}

	printf("\n");
}

/*THREAD POUR RETIRER DES ÉLÉMENTS DE LA LISTE*/
void *Pop(void *arg) {
	user_input *element = malloc(sizeof(*element));
//	Element element;

	while (1) {
		sem_wait(&semaphore);
		pthread_mutex_lock(&mutex);
		int not_empty = delete_first_element(liste_thread, element);
		pthread_mutex_unlock(&mutex);
		if (not_empty) {
			printf("supression de l'élément n°%d : %d\n", element->autre_data,
					element->nombre);
		}
		else {
			printf("empty\n");
		}
	}
	/* Pour enlever le warning */
	(void) arg;
	pthread_exit(NULL);
}

/*THREAD POUR AJOUTER DES ÉLÉMENTS À LA LISTE*/
void *Push(void *arg) {
	int val = 0;
	int num = 1;
	while (1) {
		pthread_mutex_lock(&mutex);
		add_to_list(liste_thread, val, num);
		pthread_mutex_unlock(&mutex);
		printf("\najout élément n°%d : %d à la liste\n", num, val);
		val += 10;
		num++;
		sleep(1);
		sem_post(&semaphore);
	}
	(void) arg;
	pthread_exit(NULL);
}

