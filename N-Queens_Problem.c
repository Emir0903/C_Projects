#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printBoard(int board[] , int n);
bool isSafe(int board[] , int row , int col , int n);
bool placeQueen(int bard[] , int row , int n , int target);
void countAllSol(int board[] , int row , int n);

int solCount = 0;
int found = 0;
int printed = 0;

int main(){

    int n , choose = 0;

    printf("Enter the # of Queens = ");
    scanf("%d" , &n);

    int* board = (int*)malloc(n * sizeof(int));

    while(choose != -1){

        printf("\nChoose a operation :\n"
            " 1 : Print the solution\n"
            " 2 : Just calculate the total solutions number\n"
            " 3 : Change the # of Queens\n"
            "-1 : Exit\n"
            " ? ");
        scanf("%d" , &choose);
        
        switch(choose){
            case 1:
                found  = 0; 
                if(placeQueen(board , 0 , n , printed + 1)){
                    printed++;
                    printf("\nSolution #%d :\n" , printed);
                    printBoard(board , n);
                } else {
                    printf("\nNo more solutions!\n");
                }
                break;
            case 2:
                if(solCount == 0){
                    countAllSol(board , 0 , n);
                }
                printf("\nTotal # of solutions is %d\n" , solCount);
                break;
            case 3:
                printf("\nEnter the # of Queens = ");
                scanf("%d" , &n);
                free(board);
                board = (int*)malloc(n * sizeof(int));
                solCount = 0;
                found = 0;
                printed = 0;
                break;
        }
    }
    printf("\nProgramin is terminated !");
    exit(0);
}
void countAllSol(int board[] , int row , int n){
    if(row >= n){
        solCount++;
        return;
    }
    int col;
    for(col = 0 ; col < n ; col++){
        if(isSafe(board , row , col , n)){
            board[row] = col;
            countAllSol(board , row + 1 , n);
        }
    }
}

bool placeQueen(int board[] , int row , int n , int target){
    if(row >= n){
        found++;
        return found == target;
    }
    int col;
    for(col = 0 ; col < n ; col++){
        if(isSafe(board , row , col , n)){
            board[row] = col;
            if(placeQueen(board , row + 1 , n , target)){
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int board[] , int row , int col , int n){
    int i;
    for(i = 0 ; i < row ; i++){
        if(board[i] == col || abs(i - row) == abs(board[i] - col)){
            return false;
        }
    }
    return true;
}

void printBoard(int board[] , int n){
    int i , j;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if(board[i] == j)
                printf(" Q");
            else
                printf(" -");
        }
        printf("\n");
    }
    printf("\n");
}