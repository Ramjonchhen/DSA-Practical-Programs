#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[],int low,int high,int x){
    int mid = (low+high)/2;
    if(low>high) {
        return 0;
    }
    if(arr[mid] == x) {
        return 1;
    } else if( x<arr[mid]){
        binarySearch(arr,low,mid-1,x);
    } else if ( x>arr[mid]) {
        binarySearch(arr,mid+1,high,x);
    }
}

int main()
{
   int arr[5]={1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);

if(binarySearch(arr,0,size-1,100)){
        printf("Element found");
    }else {
        printf("Element not found");
    }
    return 0;
}
