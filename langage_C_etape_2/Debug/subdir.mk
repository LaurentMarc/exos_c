################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../parpaing.c 

OBJS += \
./parpaing.o 

C_DEPS += \
./parpaing.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"

