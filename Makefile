CC := gcc
OBJDIR = temp
SRCDIR = src
BINDIR = bin
TESTDIR = tests

SOURCES := $(wildcard $(SRCDIR)/*.c)
FILTER_OUT := $(OBJDIR)/main.o
OBJECTS := $(filter-out $(FILTER_OUT),$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES)))

MAIN := $(SRCDIR)/main.c

# TEST STUFF #
ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
CMOCKA_PATH := /usr/local/lib
INCLUDE_CUSTOM_LIBS_HEADERS = -I$(ROOT_DIR)/$(SRCDIR)
INCLUDE_CMOCKA_HEADER = -lm -I /usr/local/include
INCLUDE_CMOCKA := $(INCLUDE_CMOCKA_HEADER) -l cmocka -L $(CMOCKA_PATH)
TESTS := $(basename $(notdir $(wildcard $(TESTDIR)/*.c)))
######################################################################

$(BINDIR)/main: $(OBJECTS) $(MAIN)
	$(CC) $(SRCDIR)/main.c $(OBJECTS) -o $(BINDIR)/main

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c $<

.PHONY: test
test:
	for file in $(TESTS); do \
	  $(CC) $(TESTDIR)/$$file.c $(OBJECTS) -o $(BINDIR)/$$file $(INCLUDE_CMOCKA) -I$(ROOT_DIR)/$(SRCDIR); \
	  $(BINDIR)/./$$file; \
	  done

.PHONY: clean
clean:
	rm $(OBJECTS)
	rm $(BINDIR)/main
