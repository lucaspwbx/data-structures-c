#SOURCES := $(wildcard *.c)
#OBJECTS := calculator.o words.o
MAIN := main.o
OBJECTS := $(filter-out $(MAIN),$(patsubst %.c,%.o,$(wildcard *.c)))

main: $(OBJECTS) main.c
	@echo TESTANDO: $(OBJECTS);
	gcc main.c $(OBJECTS) -o main

calculator.o: calculator.c calculator.h
	gcc -o calculator.o -c calculator.c

words.o: words.c words.h
	gcc -o words.o -c words.c

.PHONY: clean
clean:
	rm $(OBJECTS)
	rm main
