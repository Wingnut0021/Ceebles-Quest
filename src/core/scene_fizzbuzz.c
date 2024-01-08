#include <gb/gb.h>
#include <stdio.h>
#include <stdint.h>


int fizzbuzz(void) {
    int i;
    for(i=1; i<=100; ++i) {
        if(((i%3)||(i%5)) == 0)
            printf("%d FizzBuzz\n", i);
        else if((i%3) == 0)
            printf("%d Fizz\n", i);
        else if((i%5) == 0)
            printf("%d Buzz\n", i);
        else
            printf("%d\n",i);
    }
    return 0;
}