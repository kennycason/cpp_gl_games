################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/graphics/2d/shape/Point2D.cpp \
../src/graphics/2d/shape/Shape2D.cpp \
../src/graphics/2d/shape/Square.cpp 

OBJS += \
./src/graphics/2d/shape/Point2D.o \
./src/graphics/2d/shape/Shape2D.o \
./src/graphics/2d/shape/Square.o 

CPP_DEPS += \
./src/graphics/2d/shape/Point2D.d \
./src/graphics/2d/shape/Shape2D.d \
./src/graphics/2d/shape/Square.d 


# Each subdirectory must supply rules for building sources it contributes
src/graphics/2d/shape/%.o: ../src/graphics/2d/shape/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


