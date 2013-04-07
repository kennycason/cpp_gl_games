################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/graphics/Drawable.cpp \
../src/graphics/RGB.cpp \
../src/graphics/RGBA.cpp \
../src/graphics/Screen.cpp 

OBJS += \
./src/graphics/Drawable.o \
./src/graphics/RGB.o \
./src/graphics/RGBA.o \
./src/graphics/Screen.o 

CPP_DEPS += \
./src/graphics/Drawable.d \
./src/graphics/RGB.d \
./src/graphics/RGBA.d \
./src/graphics/Screen.d 


# Each subdirectory must supply rules for building sources it contributes
src/graphics/%.o: ../src/graphics/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


