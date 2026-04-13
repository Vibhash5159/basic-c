#include<stdio.h>
#include<stdlib.h>

struct stackNode{
    int data;
    struct stackNode *next;
};

struct stackNode *top = NULL;

void push(int x){
    struct stackNode *newNode =
        (struct stackNode *)malloc(sizeof(struct stackNode));

    if(newNode == NULL){
        printf("Memory overflow....\n");
        return;
    }

    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop (){
    if (top == NULL){
        printf("Memory underflow...\n");
        return;
    } else {
        struct stackNode *temp = top;
        printf("%d popped element\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek(){
    if(top == NULL){
        printf("Stack is empty.....\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

void display(){
    struct stackNode *temp = top;

    if (temp == NULL) {
        printf("Stack is empty...\n");
        return;
    }

    printf("Stack elements are:\n");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    push(15);
    push(65);
    push(99);

    display();

    pop();
    pop();

    peek();
    display();

    return 0;
}