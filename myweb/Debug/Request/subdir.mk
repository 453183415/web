################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Request/GetRequest.cpp \
../Request/Request.cpp \
../Request/RequestCreate.cpp \
../Request/RequestManager.cpp 

OBJS += \
./Request/GetRequest.o \
./Request/Request.o \
./Request/RequestCreate.o \
./Request/RequestManager.o 

CPP_DEPS += \
./Request/GetRequest.d \
./Request/Request.d \
./Request/RequestCreate.d \
./Request/RequestManager.d 


# Each subdirectory must supply rules for building sources it contributes
Request/%.o: ../Request/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


