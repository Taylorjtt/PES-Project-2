
C_SRCS = \
../board/*.c \
../CMSIS/*.c \
../drivers/*.c \
../startup/*.c \
../utilities/*.c \
../src/*.c \
../src/LED/*.c \
../src/TSS/*.c \
../src/*.c \


OBJS += \
./board/board.o \
./board/clock_config.o \
./board/peripherals.o \
./board/pin_mux.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_flash.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lpsci.o \
./drivers/fsl_rtc.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o \
./drivers/fsl_tsi_v4.o \
./CMSIS/system_MKL25Z4.o \
./startup/startup_mkl25z4.o \
./utilities/fsl_debug_console.o \
./src/main.o \
./src/mtb.o \
./src/LED/RGB.o \
./src/TSS/touch.o \
./src/semihost_hardfault.o 

C_DEPS += \
./board/*.d \
./CMSIS/*.d \
./drivers/*.d \
./startup/*.d \
./utilities/*.d \
./src/*.d \
./src/LED/*.d \
./src/TSS/*.d \

CC = arm-none-eabi-gcc
LL = arm-none-eabi-gcc

PRE = -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DSDK_DEBUGCONSOLE=0 -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG
INC = -I../board -I../src -I../ -I../drivers -I../CMSIS -I../utilities -I../startup
CFLG = -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)"
LFLG = -nostdlib -Xlinker -Map="Project_2.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m0plus -mthumb -T linkerfile.ld

# fb_debug Target
fb_debug: CC += -DDB -DFREEDOM
fb_debug: Project_2.axf 

# fb_run Target
fb_run: CC += -DFREEDOM
fb_run: Project_2.axf

pc_run: PRE =
pc_run: CFLG = -O0 -fno-common -g3 -Wall -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)"
pc_run: LFLG =
pc_run: INC = -I../src 
pc_run: C_SRCS =../src/main.c ../src/LED/RGB.c  
pc_run: OBJS = ./src/main.o ./src/LED/RGB.o 
pc_run: C_DEPS =./src/main.d ./src/LED/RGB.d
pc_run: CC =gcc
pc_run: LL =gcc
pc_run: Project_2.o

pc_debug: PRE = -DDB
pc_debug: CFLG = -O0 -fno-common -g3 -Wall -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)"
pc_debug: LFLG =
pc_debug: INC = -I../src 
pc_debug: C_SRCS =../src/main.c ../src/LED/RGB.c  
pc_debug: OBJS = ./src/main.o ./src/LED/RGB.o 
pc_debug: C_DEPS =./src/main.d ./src/LED/RGB.d
pc_debug: CC =gcc
pc_debug: LL =gcc
pc_debug: Project_2.o


# Tool invocations
Project_2.o:./src/main.o ./src/LED/RGB.o 
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	$(LL) $(LFLG) -o "Project_2.o" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Tool invocations
Project_2.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	$(LL) $(LFLG) -o "Project_2.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

startup/%.o: ../startup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	$(CC) $(PRE) $(INC) $(CFLG) -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	$(CC) $(PRE) $(INC) $(CFLG)  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
CMSIS/%.o: ../CMSIS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	$(CC) $(PRE) $(INC) $(CFLG)  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

utilities/%.o: ../utilities/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	$(CC) $(PRE) $(INC) $(CFLG)  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

board/%.o: ../board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	$(CC) $(PRE) $(INC) $(CFLG)  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	$(CC) $(PRE) $(INC) $(CFLG) -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
clean:
	-$(RM) $(EXECUTABLES) $(OBJS) Project_2.axf
	-$(RM) *.map
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Project_2.axf"; 
	-@echo ' '