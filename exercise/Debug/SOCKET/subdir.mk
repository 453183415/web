################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SOCKET/echieve-address.cpp 

OBJS += \
./SOCKET/echieve-address.o 

CPP_DEPS += \
./SOCKET/echieve-address.d 


# Each subdirectory must supply rules for building sources it contributes
SOCKET/%.o: ../SOCKET/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


