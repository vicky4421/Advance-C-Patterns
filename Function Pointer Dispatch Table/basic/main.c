#include <stdio.h>

#include "my_program.h"

int main() {
  // Declare variables for the first number, second number, choice of operation,
  // and result
  int first, second, choice, result;

  // Initialize the first number, second number, and choice of operation
  first = 2;
  second = 3;
  choice = 1;

  // Create an array of function pointers to the math functions
  math_func* func_array[] = {add, sub, mult, divide};

  // Call the chosen math function using the function pointer array and store
  // the result
  result = func_array[choice](first, second);

  printf("Result is %d\n", result);

  return 0;
}

// Function definitions for basic math operations
int add(int first, int second) { return first + second; }

int sub(int first, int second) { return first - second; }

int mult(int first, int second) { return first * second; }

int divide(int first, int second) { return first / second; }