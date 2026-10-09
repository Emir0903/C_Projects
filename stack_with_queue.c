#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef Node* Nodeptr;

void push(Nodeptr* front, Nodeptr* rear, int value);
int pop(Nodeptr* front, Nodeptr* rear);
void printQueue(Nodeptr front, Nodeptr rear);

int count = 0;

int main(){
    
    Nodeptr front = NULL;
    Nodeptr rear = NULL;

    while(1){
        int choice, value;
        printf("\n1. Push\n2. Pop\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&front, &rear, value);
                printQueue(front, rear);
                break;
            case 2:
                value = pop(&front, &rear);
                if(value != -1)
                    printf("\nPopped value: %d\n", value);
                printQueue(front, rear);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

void push(Nodeptr* front, Nodeptr* rear, int value){
    Nodeptr newNode = (Nodeptr)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (count == 0) {
        count++;
        *front = *rear = newNode;
    } else {
        count++;
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int pop(Nodeptr* front, Nodeptr* rear){
    if (count == 0) {
        printf("\nQueue is empty\n");
        return -1;
    }else if(count > 1){
        int i;
        for(i = 0; i < count - 1; i++){
            Nodeptr temp = *front;
            *front = (*front)->next;
            temp->next = NULL;
            (*rear)->next = temp;
            (*rear) = temp;
        }
        count--;
        Nodeptr temp = *front;
        int value = temp->data;
        *front = (*front)->next;
        free(temp);
        temp = NULL;
        return value;
    }else{
        count--;
        Nodeptr temp = *front;
        int value = temp->data;
        *front = (*front)->next;
        free(temp);
        *rear = NULL;
        return value;
    }
}

void printQueue(Nodeptr front, Nodeptr rear){
    printf("\nQueue: ");
    if(count == 0){printf("NULL");}
    while(front != NULL){
        printf("%d -> ", front->data);
        front = front->next;
        if(front == NULL){printf("NULL");}
    }
    printf("\n");
}
