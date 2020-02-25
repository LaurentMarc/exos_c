################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../light.c 

OBJS += \
./light.o 

C_DEPS += \
./light.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"

