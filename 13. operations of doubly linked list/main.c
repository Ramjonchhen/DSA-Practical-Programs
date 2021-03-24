#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;
int count = 0;

struct node* getNode(int x) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->prev = newnode->next = NULL;
}

void insertInHead(){
    int x; count++;
    printf("\n Enter the data to insert in the head: ");
    scanf("%d",&x);

    struct node* newnode = getNode(x);

    if(head==NULL) {
       head = newnode;
       return;
    }

    head->prev = head;
    newnode->next = head;
    head = newnode;

}

void insertInTail(){
    int x; count++;
    printf("\n Enter the data to insert in the tail: ");
    scanf("%d",&x);

    struct node* newnode = getNode(x);

    if ( head == NULL ) {
        head = newnode;
        return;
    }

    struct node* last = head;
    while(last->next!=NULL) {
        last = last->next;
    }

    last->next = newnode;
    newnode->prev = last;

}

void insertInN(){
    int pos,x,i;
    printf("\n Enter the position to insert the data: ");
    scanf("%d",&pos);


    printf("\n Enter the data to insert: ");
    scanf("%d",&x);

    struct node* newnode = getNode(x);
    struct node* travel = head;

    if(pos==1) {
            if(head==NULL) {
                head = newnode;
            } else{
                head = head->next;
                head->prev = NULL;
                free(travel);
            }
            count++;
            return;
        }

    if(pos>=1 && pos<=count+1) {
            int i ;
            for(i=1; i<pos-1; i++) {
                travel = travel->next;
            }
            newnode->prev = travel;
            newnode->next = travel->next;
            travel->next = newnode;

        count++;
    } else {
        printf("\n Invalid position to insert.");
    }
}

void deleteInHead(){
    if(head==NULL) {
        return;
    }

    if (head->next==NULL) {
        free(head);
        head = NULL;
        count--;
        return;
    }

    struct node* temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    count--;
}

void deleteAtTail(){
    if(head==NULL) {
        return;
    }

    if ( head->next == NULL ) {
        free(head);
        head = NULL;
        count--;
        return;
    }

    struct node* secondlast;
    struct node* last = head;
    while(last->next!=NULL){
        secondlast = last;
        last = last->next;
    }
    secondlast->next = NULL;
    free(last);
    count--;
}

void deleteAtN(){
    if (head==NULL) {
        return;
    }

    int pos;
    printf("\n Enter the position to delete at the linked list: ");
    scanf("%d",&pos);

    if ( pos==1 ) {
        if(head->next==NULL) {
            head = head->next;
            free(head);
        } else {
            struct node* temp = head;
            head=head->next;
            head->prev = NULL;
            free(temp);
        }
        count--;
        return;
    }

    if(pos>=1 && pos<=count) {
        int i;
        struct node* temp = head;
        for(i=1; i<pos-1; i++) {
            temp = temp->next;
        }

        if (temp->next->next==NULL) {
            free(temp->next);
            temp->next = NULL;
        } else {
            struct node* n = temp->next;
            struct node* nplus1 = n->next;
            temp->next = nplus1;
            nplus1->prev = temp;
            free(n);
        }
        count--;
    } else {
        printf("\n Position is Invalid");
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
        travel = travel->next;
        pos++;
    }while(travel!=NULL);

    found:if( found == 1) {
        printf("\n Element found at position %d",pos);
    }else {
        printf("\n Element not found");
    }
}

void display() {
    if(head==NULL) {
        printf("\n The linked list is empty.\n");
        return;
    }
    printf("\n The liked list is: ");
    struct node* display = head;
    while(display!=NULL) {
        printf("%d ",display->data);
        display = display->next;
    }
    printf("\n");
}

int main()
{
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
