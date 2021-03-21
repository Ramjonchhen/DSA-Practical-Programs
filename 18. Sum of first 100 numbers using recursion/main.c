#include <stdio.h>
#include <stdlib.h>

int sum(int n) {
    if ( n ==0 ) {
        return 0;
    } else {
        return n + sum(n-1);
    }
}
int main()
{
    printf("The sum of first 100 natural numbers is : %d",sum(100));
    return 0;
}
