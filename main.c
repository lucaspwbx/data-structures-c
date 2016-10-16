#include<stdio.h>
#include "calculator.h"
#include "words.h"

int main(void) {
  printf("Soma eh: %d\n", add(9, 10));
  printf("Sub eh: %d\n", sub(15, 10));
  printf("Palavra eh: %s\n", get());
}
