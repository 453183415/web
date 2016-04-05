################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../accept/Accept.cpp \
../accept/createAccept.cpp \
../accept/getAccept.cpp \
../accept/manageAccept.cpp 

OBJS += \
./accept/Accept.o \
./accept/createAccept.o \
./accept/getAccept.o \
./accept/manageAccept.o 

CPP_DEPS += \
./accept/Accept.d \
./accept/createAccept.d \
./accept/getAccept.d \
./accept/manageAccept.d 


# Each subdirectory must supply rules for building sources it contributes
accept/%.o: ../accept/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


