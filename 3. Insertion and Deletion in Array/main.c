#include <stdio.h>
#include <stdlib.h>

void display(int *ptr,int n) {
    printf("\n The Elements of the array is: ");
    int i;
    for(i=0; i<n; i++) {
        printf(" %d",ptr[i]);
    }
    printf("\n");
}

int main()
{
    // program to insert/ delete in array

    int n,i,choice,pos;
    printf("Enter the no of elements in array: ");
    scanf("%d",&n);

    // dyanmic memory allocation
    int *ptr = (int*)malloc(sizeof(int)*n);

    for(i=0; i<n; i++) {
        ptr[i] = 0;
    }

    display(ptr,n);

    while(1) {
        printf("\n Enter 1 for insertion in array");
        printf("\n Enter 2 for deletion in array");
         printf("\n Enter 3 for exit");
         printf("\n Enter your choice: ");
         scanf("%d",&choice);

         switch(choice)  {
        case 1:
            printf("\n Enter the position to insert: ");
            scanf("%d",&pos);
            if( pos-1>=0 && pos<=n) {
                printf("\n Enter the element to insert: ");
                scanf("%d",&ptr[pos-1]);
            }else {
                printf("\n Invalid Position");
            }
            display(ptr,n);
            break;

            case 2:
            printf("\n Enter the position to delete: ");
            scanf("%d",&pos);
            if( pos-1>=0 && pos<=n) {
                printf("\n Element Deleted: %d",ptr[pos-1]);
                ptr[pos-1] = 0;
            }else {
                printf("\n Invalid Position");
            }
            display(ptr,n);
            break;

            case 3:
                return 0;
         }
    }
    return 0;
}
