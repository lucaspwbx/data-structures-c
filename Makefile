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

$(BINDIR)/main: $(OBJECTS)
	@echo "BUILD DONE";

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -ggdb -o $@ -c $<

.PHONY: testuniq
testuniq: $(OBJECTS)
	  $(CC) -g3 -Wall -pedantic $(TESTDIR)/$(FILE)_test.c $(OBJDIR)/$(FILE).o -o $(BINDIR)/$(FILE) $(INCLUDE_CMOCKA) -I$(ROOT_DIR)/$(SRCDIR)
	  $(BINDIR)/./$(FILE)

.PHONY: test
test: $(OBJECTS)
	@echo REFATORAR;
	for file in $(TESTS); do \
	  $(CC) -g3 -Wall -pedantic $(TESTDIR)/$$file.c $(OBJDIR)/$$file.o -o $(BINDIR)/$$file $(INCLUDE_CMOCKA) -I$(ROOT_DIR)/$(SRCDIR); \
	  $(BINDIR)/./$$file; \
	  done

.PHONY: clean
clean:
	rm $(OBJECTS)
	rm $(BINDIR)/main
