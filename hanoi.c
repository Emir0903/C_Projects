#include <stdio.h>

void hanoi(int n , char source , char target , char spare){

    if(n == 1){
        printf("\nDisk 1 is moved from %c to %c" , source , target);
        return;
    }

    hanoi(n - 1, source , spare , target);

    printf("\nDisk %d is moved from %c to %c" , n , source , target);

    hanoi(n - 1 , spare , target , source);
}

int main(){

    int n;
    printf("Enter the number of Disks : ");
    scanf("%d" , &n);

    printf("\nHanoi Problem Solutions for %d Disks\n" , n);

    hanoi(n , 'A' , 'C' , 'B');
}