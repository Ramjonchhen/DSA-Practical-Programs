#include <stdio.h>
#include <stdlib.h>

int product(int x,int y) {
    if (y==0){
        return 0;
    } else {
        return x + product(x,y-1);
    }
}

int main()
{
    int a,b;
    printf("Enter A and B for A x B: \n");
    scanf("%d%d",&a,&b);
    printf("\n The Product of %d and %d is %d",a,b,product(a,b));
    return 0;
}
