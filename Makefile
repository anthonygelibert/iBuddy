# vim: noet
# 2012-06-12 — Anthony GELIBERT

# Warnings
WARNING+=-Wall -Wextra
# Standards
STD?=--std=gnu99
# Debug
DEBUG?=0
ifeq ($(DEBUG),1)
	DBG = -g3 -DDEBUG
else
	DBG = -DNDEBUG
endif
# Optimization
OPTIM?=-O2

# CC Flags
CFLAGS=$(OPTIM) $(WARNING) $(DBG) $(STD) $(shell pkg-config --cflags libusb)
# LD Flags
LDFLAGS=$(CFLAGS) $(shell pkg-config --libs libusb)

# Sources
SRC=$(wildcard *.c)
# Objects
OBJ=$(SRC:.c=.o)
# Products
EXEC=teste

all:$(EXEC)

$(EXEC): $(OBJ)

.PHONY: clean mrproper

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)
