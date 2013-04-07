################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/graphics/soil/SOIL.c \
../src/graphics/soil/image_DXT.c \
../src/graphics/soil/image_helper.c \
../src/graphics/soil/stb_image_aug.c 

OBJS += \
./src/graphics/soil/SOIL.o \
./src/graphics/soil/image_DXT.o \
./src/graphics/soil/image_helper.o \
./src/graphics/soil/stb_image_aug.o 

C_DEPS += \
./src/graphics/soil/SOIL.d \
./src/graphics/soil/image_DXT.d \
./src/graphics/soil/image_helper.d \
./src/graphics/soil/stb_image_aug.d 


# Each subdirectory must supply rules for building sources it contributes
src/graphics/soil/%.o: ../src/graphics/soil/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


