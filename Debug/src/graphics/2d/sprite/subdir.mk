################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/graphics/2d/sprite/Sprite2D.cpp 

OBJS += \
./src/graphics/2d/sprite/Sprite2D.o 

CPP_DEPS += \
./src/graphics/2d/sprite/Sprite2D.d 


# Each subdirectory must supply rules for building sources it contributes
src/graphics/2d/sprite/%.o: ../src/graphics/2d/sprite/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


