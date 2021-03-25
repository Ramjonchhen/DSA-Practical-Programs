#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[],int size,int x,int i) {
    if(arr[i]==x) {
        return 1;
    } if(i==size) {
        return 0;
    }
    linearSearch(arr,size,x,i+1);
}

int main()
{
    int arr[5]={1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);

    if(linearSearch(arr,size,1,0)){
        printf("Element found");
    }else {
        printf("Element not found");
    }
    return 0;
}
