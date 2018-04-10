################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Agency.cpp \
../src/City.cpp \
../src/Client.cpp \
../src/Coordinates.cpp \
../src/Date.cpp \
../src/Flight.cpp \
../src/Hotel.cpp \
../src/Menu.cpp \
../src/Trip.cpp 

OBJS += \
./src/Agency.o \
./src/City.o \
./src/Client.o \
./src/Coordinates.o \
./src/Date.o \
./src/Flight.o \
./src/Hotel.o \
./src/Menu.o \
./src/Trip.o 

CPP_DEPS += \
./src/Agency.d \
./src/City.d \
./src/Client.d \
./src/Coordinates.d \
./src/Date.d \
./src/Flight.d \
./src/Hotel.d \
./src/Menu.d \
./src/Trip.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


