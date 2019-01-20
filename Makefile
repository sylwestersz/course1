#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------

#sources and include directories are tracked separately in the file:
include sources.mk

# Platform Overrides in case none defined
PLATFORM = HOST

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
#SPECS = 

# Compiler Flags and Defines
TARGET = final

#CPPFLAGs = 

ifeq ($(PLATFORM), MSP432)

	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	CPU = cortex-m4
	ARCH = armv7e-m
	LDFLAGS =  -T $(LINKER_FILE)

	#all source files will be compiled into object files for MSP432
	OBJS := $(SOURCES_COMMON:.c=.o) $(SOURCES_MPS432:.c=.o)
	INCLUDE_DIRS = $(INCLUDE_DIRS_COMMON) $(INCLUDE_DIRS_MPS432)

	CFLAGS = -Wall -Werror -O0 -std=c99 -D $(PLATFORM) $(INCLUDE_DIRS) \
			 -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
			 --specs=nosys.specs

else ifeq ($(PLATFORM), HOST)

	CC = gcc
	LD = ld
	CPU = amd64
	ARCH := $(shell arch)	

	#only common library code no ARM specifics for HOST needed
	OBJS := $(SOURCES_COMMON:.c=.o)
	INCLUDE_DIRS = $(INCLUDE_DIRS_COMMON) 

	CFLAGS = -Wall -Werror -O0 -std=c99 -D $(PLATFORM) -D COURSE1 -D VERBOSE $(INCLUDE_DIRS)

else
	#echo "Please specify know PLATFORM ('MSP432' or 'HOST')!"
endif

# vpath directive used for header file search 
vpath %.h $(INCLUDE_DIRS)

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

#Generate map file for main
%.map: %.out
	$(CC) -Map=$(TARGET).out $(CFLAGS) $< -o $@

# include the header dependencies to make sure target are updated uf header changes
main.o : platform.h
memory.o main.o : memory.h
system_msp432p401r.o. : msp432p401r.h

# decided to put all HPONY targets last
.PHONY: build
build: $(TARGET).out

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map *.s *.i *.asm

