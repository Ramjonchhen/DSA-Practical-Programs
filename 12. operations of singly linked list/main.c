#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* head;
struct node* tail;

int count = 0;

struct node* getNode(int x) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = NULL;
    return newnode;
}

void insertInHead(){
    int x;
    printf("\n Enter the data to insert in the head: ");
    scanf("%d",&x);

    struct node* newnode = getNode(x);
    newnode->link = head;
    head=newnode;
    count++;
}

void insertInTail() {
     int x;
    printf("\n Enter the data to insert in the tail: ");
    scanf("%d",&x);

    struct node* newnode = getNode(x);

    if( head == NULL ) {
        head = newnode;
        return;
    }
    struct node* temp = head;

    while(temp->link!=NULL) {
        temp = temp->link;
    }

    temp->link = newnode;
    count++;
}

void insertInN() {
    int pos,x,i;
    printf("\n Enter the position to insert the data: ");
    scanf("%d",&pos);


    printf("\n Enter the data to insert: ");
    scanf("%d",&x);

    struct node* newnode = getNode(x);
    struct node* travel = head;

    if ( pos == 1) {
        newnode->link = head;
        head = newnode;
        count++;
        return;
    }

    if( pos <1 || pos >count ) {
        printf("\n The Position is Invalid. \n");
        return;
    }

    for(i=1; i<pos-1; i++) {
        travel = travel->link;
    }

    newnode->link = travel->link;
    travel->link = newnode;
    count++;
}


void deleteInHead() {
    if(head == NULL ) {
        printf("\n The linked list is empty.");
        return;
    }
    struct node* temp = head;
    head = head->link;
    free(temp);
    count--;
}

void deleteAtTail() {
    if (head==NULL) {
        printf("\n The linked list is empty.");
        return;
    }

    struct node* secondLast;
    struct node* last = head;

    while(last->link!=NULL) {
        secondLast= last;
        last = last->link;
    }

    secondLast->link = NULL;
    free(last);
    count--;
}

void deleteAtN() {
    int pos,i;

    printf("\n Enter the position to delete in the list: ");
    scanf("%d",&pos);

    if ( pos>=1 && pos<=count) {

        if ( pos == 1) {
            struct node* temp = head;
            head = head->link;
            free(temp);
            count--;
            return;
        }

        struct node* nminus1 = head;
        for(i = 1; i<pos-1; i++) {
            nminus1 = nminus1->link;
        }

        struct node* n = nminus1->link;
        struct node* nplus1 = n->link;

        nminus1->link = nplus1;
        free(n);
        count--;
    } else {
        printf("\n The Position is invalid.");
    }
}

void search(){
    if (head == NULL) {
        return;
    }
    int x;
    printf("\n Enter the element to search in the linked list: ");
    scanf("%d",&x);

    int found = 0 , pos = 1;
    struct node* travel = head;
    do{
        if(travel->data == x) {
            found = 1;
            goto found;
        }
        travel = travel->link;
        pos++;
    }while(travel!=NULL);

    found:if( found == 1) {
        printf("\n Element found at position %d",pos);
    }else {
        printf("\n Element not found");
    }
}

void display() {
    struct node *travel = head;

    if(travel == NULL ) {
        printf("\n The Linked List is Empty. \n");
        return;
    }
    printf("\n The contents of the linked list is: ");
    while(travel!=NULL){
        printf("%d ",travel->data);
        travel = travel->link;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    int choice;
    while(1) {
        printf("\n Enter 1 to insert in the head:");
        printf("\n Enter 2 to insert in the tail:");
        printf("\n Enter 3 to insert in the n th:");
        printf("\n Enter 4 to delete in the head:");
        printf("\n Enter 5 to delete in the tail:");
        printf("\n Enter 6 to delete in the n th:");
        printf("\n Enter 7 to traverse the list.");
        printf("\n Enter 8 to search in the list.");
        printf("\n Enter 9 to count in the list");
        printf("\n Enter 10 to exit the menu.");
        printf("\n Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
        case 1:
            insertInHead();
            display();
            break;

        case 2:
            insertInTail();
            display();
            break;

        case 3:
            insertInN();
            display();
            break;

        case 4:
            deleteInHead();
            display();
            break;

        case 5:
            deleteAtTail();
            display();
            break;

        case 6:
            deleteAtN();
            display();
            break;

        case 7:
            display();
            break;

        case 8:
            search();
            display();
            break;

        case 9:
            printf("\n The no of nodes in the linked list is: %d \n",count);
            display();
            break;

        case 10:
            return 0;
        }
    }

    return 0;
}
