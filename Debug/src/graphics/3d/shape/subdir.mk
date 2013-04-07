################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/graphics/3d/shape/Cube.cpp \
../src/graphics/3d/shape/Shape3D.cpp 

OBJS += \
./src/graphics/3d/shape/Cube.o \
./src/graphics/3d/shape/Shape3D.o 

CPP_DEPS += \
./src/graphics/3d/shape/Cube.d \
./src/graphics/3d/shape/Shape3D.d 


# Each subdirectory must supply rules for building sources it contributes
src/graphics/3d/shape/%.o: ../src/graphics/3d/shape/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


