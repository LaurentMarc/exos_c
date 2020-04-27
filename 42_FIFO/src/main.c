#include "list.h"

sem_t semaphore;
/*
 void test_manipulation_liste_chainee(void) {
 Element element;

 queue *maliste = initialiser();

 add_to_list(maliste, 4, 1);
 add_to_list(maliste, 8, 2);
 add_to_list(maliste, 15, 3);
 add_to_list(maliste, 16, 4);
 add_to_list(maliste, 23, 5);
 add_to_list(maliste, 42, 6);
 add_to_list(maliste, 26, 7);
 add_to_list(maliste, 3, 8);

 printf("\nEtat de la file :\n");
 show_list(maliste);

 element = delete_first_element(maliste);
 printf("\nJe retire %d, élément n°%d\n", element.nombre,
 element.autre_data);
 element = delete_first_element(maliste);
 printf("\nJe retire %d, élément n°%d\n", element.nombre,
 element.autre_data);
 element = delete_first_element(maliste);
 printf("\nJe retire %d, élément n°%d\n", element.nombre,
 element.autre_data);

 printf("\nEtat de la file :\n");
 show_list(maliste);

 }
 */

int main() {

	pthread_mutex_init(&mutex, NULL);
	sem_init(&semaphore, 0, 1);

	liste_thread = initialiser();

//	test_manipulation_liste_chainee();

	printf("création thread suppression éléments\n");
	pthread_t pop;
	printf("création thread ajout éléments\n");
	pthread_t push;
	pthread_create(&pop, NULL, Pop, NULL);
	pthread_create(&push, NULL, Push, NULL);

	pthread_join(pop, NULL);
	pthread_join(push, NULL);

	return 0;
}

