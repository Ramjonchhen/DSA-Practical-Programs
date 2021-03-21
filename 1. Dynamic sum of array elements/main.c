#include <stdio.h>
#include <stdlib.h>

int main()
{
    // program to read n numbers dynamically and find their sum
    int n;
    printf("Enter the no of elements to find sum: ");
    scanf("%d",&n);

    // dyanmic memory allocation
    int *ptr = (int*)malloc(sizeof(int)*n);

    printf("\n Enter the elements of the array: \n");
    int i, sum = 0;

    for( i=0; i<n; i++) {
        printf("\n Enter the %d element: ",i+1);
        scanf("%d",&ptr[i]);
        sum+=ptr[i];
    }

    printf("\n The sum of %d elements is %d ",n,sum);
    return 0;
}
