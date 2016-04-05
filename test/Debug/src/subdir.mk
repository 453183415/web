################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/tcpServer.cpp \
../src/test.cpp \
../src/test1.cpp \
../src/udp_client.cpp 

OBJS += \
./src/tcpServer.o \
./src/test.o \
./src/test1.o \
./src/udp_client.o 

CPP_DEPS += \
./src/tcpServer.d \
./src/test.d \
./src/test1.d \
./src/udp_client.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


