#include <stdio.h>
#include <stdlib.h>

#define size 4

int stack[size];
int tos = -1;

int isEmpty() {
    return tos == -1 ? 1 : 0 ;
}

int isFull() {
    return tos == size-1 ? 1 : 0;
}

void push() {
    if(isFull()) {
        printf("\n Stack is Full Can't Insert");
        return;
    }
    printf("\n Enter the element to push: ");
    scanf("%d",&stack[++tos]);
}

void pop() {
    if(isEmpty()) {
        printf("\n Stack is Empty. Nothing to pop");
        return;
    }
    printf("\n %d pop from stack",stack[tos]);
    tos--;
}

void top() {
    if(isEmpty()) {
        printf("\n Stack is Empty. ");
        return;
    }
    printf("\n The top of stack is: %d",stack[tos]);
}

int main()
{
    int choice;

     while(1) {
        printf("\n Enter 1 for pushing in stack.");
        printf("\n Enter 2 for pop in stack");
         printf("\n Enter 3 for top of stack operation.");
         printf("\n Enter 4 for exit.");
         printf("\n Enter your choice: ");
         scanf("%d",&choice);

         switch(choice)  {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            top();
            break;

        case 4:
            return 0;
         }

     }
    return 0;
}
