#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef Node* Nodeptr;

void enqueue(Nodeptr* topIn, Nodeptr* topOut, int value);
int dequeue(Nodeptr* topIn, Nodeptr* topOut);
void printStacks(Nodeptr topIn, Nodeptr topOut);

int countIn = 0 , countOut = 0;

int main(){

    Nodeptr topIn = NULL;
    Nodeptr topOut = NULL;

    while(1){
        int choice, value;
        printf("\n1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&topIn, &topOut, value);
                printStacks(topIn, topOut);
                break;
            case 2:
                value = dequeue(&topIn, &topOut);
                if(value != -1)
                    printf("\nDequeued value: %d\n", value);
                printStacks(topIn, topOut);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

void enqueue(Nodeptr* topIn, Nodeptr* topOut, int value){
    Nodeptr newNode = (Nodeptr)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    countIn++;
    newNode->next = *topIn;
    *topIn = newNode;
}

int dequeue(Nodeptr* topIn, Nodeptr* topOut){

    if(countIn == 0 && countOut == 0){
        printf("\nQueue is empty\n");
        return -1;
    }

    if(countOut == 0){
        while(countIn != 0){
            Nodeptr temp = *topIn;
            *topIn = (*topIn)->next;
            temp->next = *topOut;
            *topOut = temp;
            countIn--;
            countOut++;
        }
    }

    Nodeptr temp = *topOut;
    int value = temp->data;
    *topOut = (*topOut)->next;
    free(temp);
    countOut--;
    return value;
}

void printStacks(Nodeptr topIn, Nodeptr topOut){
    printf("\nStack In: ");
    if(topIn == NULL){printf("NULL");}
    while(topIn != NULL){
        printf("%d -> ", topIn->data);
        topIn = topIn->next;
        if(topIn == NULL){printf("NULL");}
    }
    printf("\n");

    printf("\nStack Out: ");
    if(topOut == NULL){printf("NULL");}
    while(topOut != NULL){
        printf("%d -> ", topOut->data);
        topOut = topOut->next;
        if(topOut == NULL){printf("NULL");}
    }
    printf("\n");
}
