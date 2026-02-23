#include <stdio.h>

#include "my_program.h"

int main() {
  int first, second, choice, result;

  first = 2;
  second = 3;
  choice = 1;

  math_func* func_array[] = {add, sub, mult, divide};

  result = func_array[choice](first, second);

  printf("Result is %d\n", result);

  return 0;
}

int add(int first, int second) { return first + second; }

int sub(int first, int second) { return first - second; }

int mult(int first, int second) { return first * second; }

int divide(int first, int second) { return first / second; }