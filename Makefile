
STD?=--std=gnu99
DEBUG?=-g3
OPTIM?=-O2


CFLAGS=$(OPTIM) $(DEBUG) $(STD) $(shell pkg-config --cflags libusb)
LDFLAGS=$(CFLAGS) $(shell pkg-config --libs libusb)

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
EXEC=teste

all:$(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean mrproper

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)
