//
// Created by guessever on 4/29/17.
//

#include <stdio.h>

int a[100000000];

int main() {
    for (int t = 0; t < 10; t++)
        for (int i = 0; i < 100000000; i++) a[i] = i;
    printf("hello world, again\n");
    return 0;
}
