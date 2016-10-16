OBJECTS := calculator.o words.o

main: $(OBJECTS) main.c
	gcc main.c $(OBJECTS) -o main

calculator.o: calculator.c calculator.h
	gcc -o calculator.o -c calculator.c

words.o: words.c words.h
	gcc -o words.o -c words.c

clean:
	rm $(OBJECTS)
	rm main
