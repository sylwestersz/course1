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
include sources.mk
#INCLUDE_DIRS = 
# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
#CPU = 
#ARCH = 
#SPECS = 

# Compiler Flags and Defines
ifeq ({$PLATFORM}, MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
else ifeq ({$PLATFORM}, HOST)
	CC = gcc
	LD = ld
else
	echo Please specify know PLATFORM ('MSP432' or 'HOST')!
endif

#LDFLAGS = 
#CFLAGS = 
#CPPFLAGs = 

OBJS = $(SRCS:.c=.o)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map

c1m2.out: ($OBJS)
