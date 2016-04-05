################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../response/byeBase.cpp \
../response/cdBase.cpp \
../response/delBase.cpp \
../response/errorBase.cpp \
../response/getBase.cpp \
../response/loginBase.cpp \
../response/lsBsae.cpp \
../response/putBase.cpp \
../response/response.cpp \
../response/responseBase.cpp 

OBJS += \
./response/byeBase.o \
./response/cdBase.o \
./response/delBase.o \
./response/errorBase.o \
./response/getBase.o \
./response/loginBase.o \
./response/lsBsae.o \
./response/putBase.o \
./response/response.o \
./response/responseBase.o 

CPP_DEPS += \
./response/byeBase.d \
./response/cdBase.d \
./response/delBase.d \
./response/errorBase.d \
./response/getBase.d \
./response/loginBase.d \
./response/lsBsae.d \
./response/putBase.d \
./response/response.d \
./response/responseBase.d 


# Each subdirectory must supply rules for building sources it contributes
response/%.o: ../response/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


