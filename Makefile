main: calculator.o words.o main.c
	gcc main.c calculator.o words.o -o main

calculator.o: calculator.c calculator.h
	gcc -o calculator.o -c calculator.c

words.o: words.c words.h
	gcc -o words.o -c words.c

clean:
	rm calculator.o
	rm words.o
	rm main
