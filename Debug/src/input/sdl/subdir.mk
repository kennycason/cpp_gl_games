################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/input/sdl/SDLKeyBoard.cpp 

OBJS += \
./src/input/sdl/SDLKeyBoard.o 

CPP_DEPS += \
./src/input/sdl/SDLKeyBoard.d 


# Each subdirectory must supply rules for building sources it contributes
src/input/sdl/%.o: ../src/input/sdl/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


