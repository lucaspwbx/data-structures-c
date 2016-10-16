#SOURCES := $(wildcard *.c)
#OBJECTS := calculator.o words.o
#MAIN := main.o
#OBJECTS := $(filter-out $(MAIN),$(patsubst %.c,%.o,$(wildcard *.c)))
CC := gcc
OBJDIR = temp
SRCDIR = src
BINDIR = bin
TESTDIR = tests
OBJECTS := $(OBJDIR)/calculator.o $(OBJDIR)/words.o
MAIN := $(SRCDIR)/main.c

# TEST STUFF #
ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
CMOCKA_PATH := /usr/local/lib
INCLUDE_CUSTOM_LIBS_HEADERS = -I$(ROOT_DIR)/$(SRCDIR)
INCLUDE_CMOCKA_HEADER = -lm -I /usr/local/include
INCLUDE_CMOCKA := $(INCLUDE_CMOCKA_HEADER) -l cmocka -L $(CMOCKA_PATH)
######################################################################

$(BINDIR)/main: $(OBJECTS) $(MAIN)
	$(CC) $(SRCDIR)/main.c $(OBJECTS) -o $(BINDIR)/main
	$(BINDIR)/./main

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c $<

.PHONY: tests
tests:
	@echo $(ROOT_DIR);
	$(CC) $(TESTDIR)/calculator_test.c $(OBJECTS) -o $(BINDIR)/calculator_test $(INCLUDE_CMOCKA) -I/Users/lucasweiblen/estudos/make/ch2/$(SRCDIR)
	$(BINDIR)/./calculator_test

.PHONY: clean
clean:
	rm $(OBJECTS)
	rm $(BINDIR)/main
	rm $(BINDIR)/calculator_test
