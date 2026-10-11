#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int values[100];
    int top;
} Stack;

typedef struct {
    char name[3];
    int count;
} Element;

void push(Stack *s, int value);
int pop(Stack *s);

char formula[100];
Element elements[118]; // Assuming a maximum of 118 elements in the periodic table
int elementCount = 0; // Count of unique elements found in the formula

int main(){

    int total = 0; // Total number of atoms
    int genCoef = 1; // General coefficient for nested groups
    int curCoef = 0; // Current coefficient for the current element or group
    int digit = 1; // Multiplier for digits in coefficients
    char tempLetter = '\0'; // Temporary variable to hold the current letter being processed

    Stack s;
    s.top = -1;

    printf("\nEnter a chemical formula: ");
    scanf("%s", formula);

    int i;
    for(i = strlen(formula) - 1 ; i >= 0; i--){
        if(isdigit(formula[i])){
            curCoef += (formula[i] - '0') * digit;
            digit *= 10;
        }else if(formula[i] == ')'){
            if(curCoef == 0) curCoef = 1;
            push(&s, curCoef);
            genCoef *= curCoef;
            curCoef = 0;
            digit = 1;
        }else if(formula[i] == '('){
            int temp = pop(&s);
            genCoef /= temp;
            curCoef = 0;
            digit = 1;
        }else if(islower(formula[i])){
            tempLetter = formula[i];
        }
        else{
            if(curCoef == 0) curCoef = 1;
            char tempName[3] = {formula[i], tempLetter, '\0'};

            int j;
            int found = 0;
            for(j = 0 ; j < elementCount; j++){
                if(strcmp(elements[j].name, tempName) == 0){
                    elements[j].count += curCoef * genCoef;
                    found = 1;
                    break;   
                }
            }

            if(found == 0){
                strcpy(elements[elementCount].name, tempName);
                elements[elementCount].count = curCoef * genCoef;
                elementCount++;
            }

            tempLetter = '\0';
            curCoef = 0;
            digit = 1;
        }
    }

    printf("\nAtom counts:\n");
    for(i = 0; i < elementCount; i++){
        total += elements[i].count;
        printf(" %s: %d\n", elements[i].name, elements[i].count);
    }
    printf("Total atoms: %d\n", total);
}

void push(Stack *s, int value) {
    if (s->top < 100) {
        s->values[++(s->top)] = value;
    } else {
        printf("Stack overflow\n");
    }
}

int pop(Stack *s) {
    if (s->top >= 0) {
        return s->values[(s->top)--];
    } else {
        printf("Stack underflow\n");
        return -1; // Or some other error value
    }
}