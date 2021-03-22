#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node* link;
};

struct node* tos = NULL;

char *infix;
char *postfix;
int count = 0;

int isEmpty() {
    return tos == NULL ? 1 : 0;
}

char top() {
    return tos->data;
}

void push(char input) {

    struct node* newnode = (struct node* )malloc(sizeof(struct node));
    newnode->data = input;
    newnode->link = NULL;

    newnode->link = tos;
    tos = newnode;
}

void pop() {
    struct node* temp = tos;
    tos = tos->link;
    free(temp);
}

int isOperand(char x) {
    if ( (x>='A' && x<='Z') || (x>='a' && x<='z') || (x>='0' && x<='9') ) {
        return 1;
    } else {
        return 0;
    }
}

int isOperator(char x) {
    if( x=='+' || x=='-'|| x=='/' || x=='*' || x=='^' ) {
        return 1;
    }else {
        return 0;
    }
}

int getOperatorWeight(char opt) {
    int weight = -1;
    switch( opt ) {
    case '+':
    case '-':
        weight = 1;
        break;

    case '/':
    case '*':
        weight = 2;
        break;

    case '^':
        weight = 3;
        break;
    }
    return weight;
}

int isRightAssociative(char x) {
    return x == '^' ? 1 : 0;
}

int hasHigherPrecedence(char stack,char infix) {
    int stackwt = getOperatorWeight(stack);
    int infixwt = getOperatorWeight(infix);

    if( stackwt==infixwt ) {
        if(isRightAssociative(stack)){
            return 0;
        }
        return 1;
    }
    return stackwt>infixwt ? 1 : 0;
}

int isOpeningBracket(char x) {
    return x=='(' || x=='{' || x=='[' ? 1: 0;
}

int isClosingBracket(char x) {
    return x==')' || x=='}' || x==']' ? 1: 0;
}

void infixToPostfix(char *infix,int n) {
    int i;
    for(i=0; i<n; i++) {
        if(infix[i]==' '  || infix[i]==',') {
            continue;
        }

        else if( isOperand(infix[i]) ) {
            postfix[count++] = infix[i];
        }

        else if( isOperator(infix[i]) ) {
            while( !isEmpty() && !isOpeningBracket(top()) &&hasHigherPrecedence(top(),infix[i])  ) {
                postfix[count++] = top();
                pop();
            }
            push(infix[i]);
        }

        else if(isOpeningBracket(infix[i])) {
            push(infix[i]);
        }
        else if( isClosingBracket(infix[i])) {
            while(!isEmpty() && !isOpeningBracket(top()) ) {
                postfix[count++] = top();
                pop();
            }
            pop();
        }
    }
    while(!isEmpty() ) {
        postfix[count++] = top();
        pop();
    }
}

int main()
{
    int n;
    printf("Enter the length of the infix string: ");
    scanf("%d",&n);

    infix = (char*)malloc(sizeof(char)*n+1);
    postfix = (char*)malloc(sizeof(char)*n+1);

    printf("\n enter the infix string: ");
    scanf("%s",infix);

    infixToPostfix(infix,n);

    int i;
    printf("\n The equivalent postfix form is: ");
    for(i=0; i<count; i++) {
        printf("%c",postfix[i]);
    }
    return 0;
}
