#include <stdio.h>
#include <stdlib.h>

int sumOfDigit(int num) {
    if(num==0) {
        return 0;
    }
    return num%10 + sumOfDigit(num/10);
}

int main()
{
    int x;
    printf("Enter the number to find the sum of digit: ");
    scanf("%d",&x);

    printf("\nThe sum of digit is: %d",sumOfDigit(x));
    return 0;
}
