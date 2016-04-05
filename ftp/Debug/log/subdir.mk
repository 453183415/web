################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../log/ErrorLog.cpp \
../log/Log.cpp 

OBJS += \
./log/ErrorLog.o \
./log/Log.o 

CPP_DEPS += \
./log/ErrorLog.d \
./log/Log.d 


# Each subdirectory must supply rules for building sources it contributes
log/%.o: ../log/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


