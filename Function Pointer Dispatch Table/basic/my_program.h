#ifndef MY_PROGRAM_H
#define MY_PROGRAM_H

// Function prototypes for basic math operations
int add(int first, int second);
int sub(int first, int second);
int mult(int first, int second);
int divide(int first, int second);

// typedef for a function pointer to a math function
typedef int math_func(int first, int second);

#endif