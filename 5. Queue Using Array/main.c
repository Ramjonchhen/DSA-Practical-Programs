#include <stdio.h>
#include <stdlib.h>

#define size 3

int front = -1, rear =-1;

int queue[size];

int isEmpty() {
    return front==-1 & rear==-1 ? 1: 0;
}

int isFull() {
    return rear==size-1 ? 1: 0;
}

void enqueue() {
    if( isFull()) {
        printf("\n queue is full.");
        return;
    }

    int x;
    printf("\n Enter the element to enqueue: ");
    scanf("%d",&x);

    if( isEmpty() ) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = x;
}

void dequeue() {
    if( isEmpty() ) {
        printf("\n Queue is empty. ");
        return;
    }
    printf("\n Element Dequeued: %d",queue[front]);
    if( front == rear){
        front = rear = -1;
    } else {
        front++;
    }
}

int main()
{
    int choice;

     while(1) {
        printf("\n Enter 1 for enqueue operation.");
        printf("\n Enter 2 for dequeue operation.");
         printf("\n Enter 3 for exit.");
         printf("\n Enter your choice: ");
         scanf("%d",&choice);

         switch(choice)  {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            return 0;
         }

     }
    return 0;
}
