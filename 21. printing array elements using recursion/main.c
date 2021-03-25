#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[],int n,int size){
    if(n==size){
        return;
    }
    printf("Array element arr[%d]: %d \n",n,arr[n]);
    printArray(arr,n+1,size);
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    printArray(arr,0,size);
    return 0;
}
