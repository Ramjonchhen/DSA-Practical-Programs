#include <stdio.h>
#include <stdlib.h>

int fibbonaci(int n) {
    if( n == 0 ) {
        return 0;
    } else if( n == 1 ) {
        return 1;
    } else {
        return fibbonaci(n-1) + fibbonaci(n-2);
    }
}
int main()
{
    printf("The Fibbonaci Sequence of first 10 numbers are: ");
    int i = 0;
    for(i=0; i<10; i++) {
        printf(" %d",fibbonaci(i));
    }
    return 0;
}
