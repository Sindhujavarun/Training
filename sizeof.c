// print size of char, int, char*, int*, float*, char**

#include<stdio.h>
int main() 
{
    int intType;
    float floatType;
    char charType;
    printf("Size of char: %zu byte\n", sizeof(charType));
    printf("Size of char*: %zu byte\n", sizeof(char*));
    printf("Size of char**: %zu byte\n", sizeof(char**));
    printf("Size of int: %zu bytes\n", sizeof(intType));
    printf("Size of int*: %zu bytes\n", sizeof(int*));
    printf("Size of float*: %zu bytes\n", sizeof(float*));
    return 0;
}