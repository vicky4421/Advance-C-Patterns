#ifndef MY_PROGRAM_H
#define MY_PROGRAM_H

int add(int first, int second);
int sub(int first, int second);
int mult(int first, int second);
int divide(int first, int second);

typedef int math_func(int first, int second);

#endif