#SOURCES := $(wildcard *.c)
#OBJECTS := calculator.o words.o
OBJDIR = temp
SRCDIR = src
BINDIR = bin
#MAIN := main.o
#OBJECTS := $(filter-out $(MAIN),$(patsubst %.c,%.o,$(wildcard *.c)))
OBJECTS := $(OBJDIR)/calculator.o $(OBJDIR)/words.o
MAIN := $(SRCDIR)/main.c

$(BINDIR)/main: $(OBJECTS) $(MAIN)
	gcc $(SRCDIR)/main.c $(OBJECTS) -o $(BINDIR)/main

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc -o $@ -c $<

.PHONY: clean
clean:
	rm $(OBJECTS)
	rm $(BINDIR)/main
