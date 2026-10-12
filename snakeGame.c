#include <stdio.h>
#include <stdlib.h>

#include <conio.h>
#include <windows.h>

#include <time.h>

#define WIDTH 40
#define HEIGHT 20

typedef struct Snake {
    int x;
    int y;
    struct Snake* next;
} Snake;

Snake* front = NULL;
Snake* rear = NULL;

char map[HEIGHT][WIDTH];

void initializeMap() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if(i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1){
                map[i][j] = '#'; // Border
            } else {
                map[i][j] = ' '; // Empty space
            }
        }
    }
}

void enqueue(int x, int y) {
    Snake* newNode = (Snake*)malloc(sizeof(Snake));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        map[rear->y][rear->x] = 'o'; // Clear the previous position of the snake's head
        rear->next = newNode;
        rear = newNode;
    }

    map[y][x] = 'O'; // Mark the snake's position (Head) on the map
}

void dequeue(){
    if (front == NULL) {
        return; // Queue is empty
    }

    Snake* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL; // Queue is now empty
    }

    map[temp->y][temp->x] = ' '; // Clear the position of the snake's tail on the map
    free(temp);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void printMap(){
    gotoxy(0, 0); // Move the cursor to the top-left corner of the console

    int i , j;
    for(i = 0; i < HEIGHT; i++){
        for(j = 0; j < WIDTH; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void spawnApple() {
    int rX, rY;

    do {
        rX = rand() % WIDTH;
        rY = rand() % HEIGHT;
    } while (map[rY][rX] != ' ');

    map[rY][rX] = '*';
}

int main(){
    hideCursor();
    srand(time(NULL)); // Seed the random number generator
    initializeMap();

    enqueue(WIDTH / 2, HEIGHT / 2); // Start the snake in the middle of the map
    spawnApple();

    int dx = 0;
    int dy = 0;
    int gg = 0;

    while(!gg){
        if(_kbhit()){
           char key = _getch();

            if(key == 'w'&& dy == 0){ dx = 0; dy = -1;}
            else if(key == 's' && dy == 0){dx = 0; dy = 1;}
            else if(key == 'a' && dx == 0){dx = -1; dy = 0;}
            else if(key == 'd' && dx == 0){dx = 1; dy = 0;}
            else if(key == 'q'){gg = 1; break;} // Quit the game
        }

        if(dx == 0 && dy == 0){ // If no direction is set, continue to the next iteration
            printMap();
            Sleep(150);
            continue;
        }

        int tempX = rear->x + dx;
        int tempY = rear->y + dy;

        if(map[tempY][tempX] == '#' || map[tempY][tempX] == 'o'){ // Check for collision with walls or the snake itself
            gg = 1;
            break;
        }else if(map[tempY][tempX] == '*'){ // Check for collision with the snake's head
            enqueue(tempX, tempY); // Grow the snake
            spawnApple(); // Spawn a new apple
        }else{
            enqueue(tempX, tempY); // Move the snake
            dequeue(); // Remove the tail
        
            printMap();
            Sleep(150); // Control the speed of the snake
        }
    }

    system("cls"); // Clear the console for the next frame
    printf("\n----------------{ GAME OVER }----------------\n");

    return 0;
}