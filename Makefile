# vim: noet
# 2012-06-12 — Anthony GELIBERT

# Warnings
WARNING := -W -Wall -Wextra
# Standards
STD := --std=gnu99
# Debug
DEBUG ?= 0
ifeq ($(DEBUG),1)
	DBG = -g3 -DDEBUG
else
	DBG = -DNDEBUG
endif
# Optimization
OPTIM := -O2

# CC Flags
CFLAGS += $(OPTIM) $(WARNING) $(DBG) $(STD) $(shell pkg-config --cflags libusb)
# LD Flags
LDFLAGS += $(CFLAGS) $(shell pkg-config --libs libusb)

# Sources
SRC := $(wildcard *.c)
# Objects
OBJ := $(SRC:.c=.o)
# Products
EXEC := teste

.PHONY: all clean distclean

all:$(EXEC)

$(EXEC): $(OBJ)

clean:
	@- $(RM) $(OBJ)
	@- $(RM) $(EXEC)

distclean: clean
