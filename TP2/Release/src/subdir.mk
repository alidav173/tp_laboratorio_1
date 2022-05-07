################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TP2.c \
../src/arrayPassenger.c \
../src/funciones.c \
../src/inputs.c 

C_DEPS += \
./src/TP2.d \
./src/arrayPassenger.d \
./src/funciones.d \
./src/inputs.d 

OBJS += \
./src/TP2.o \
./src/arrayPassenger.o \
./src/funciones.o \
./src/inputs.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/TP2.d ./src/TP2.o ./src/arrayPassenger.d ./src/arrayPassenger.o ./src/funciones.d ./src/funciones.o ./src/inputs.d ./src/inputs.o

.PHONY: clean-src

