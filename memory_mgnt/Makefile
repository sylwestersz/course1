# simple makefile used for practice

#sources and include directories are tracked separately in the file:
SRCS = main.c misc.c 

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds

# Compiler Flags and Defines
TARGET = c1m3

CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
CPU = cortex-m4
ARCH = armv7e-m
LDFLAGS =  -T $(LINKER_FILE)

#all source files will be compiled into object files for MSP432
OBJS := $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -O0 -std=c99 -mcpu=$(CPU) -mthumb \
		 -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
		 --specs=nosys.specs

# make main target the default one
$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

#Generate object files
%.o: %.c
	$(CC) -c $(CFLAGS) $(LDFLAGS) $< -o $@

#Generate preprocessor output
%.i: %.c
	$(CC) -E $(CFLAGS) $< -o $@

#Generate assembly output
%.asm: %.c
	$(CC) -S $(CFLAGS) $< -o $@

#Generate dependency files
%.asm: %.c
	$(CC) -MP $(CFLAGS) $< -o $@

#Generate dependency files
%.map: %.out
	$(CC) -Map=$(TARGET).out $(CFLAGS) $< -o $@

# decided to put all HPONY targets last
.PHONY: build
build: $(TARGET).out

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map *.s *.i

