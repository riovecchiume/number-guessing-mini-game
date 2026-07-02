#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void play();
int guess();
void otherOption();
int guessCount();
void evaluator(int g, int const c);
void inputDetection();
void clear();

int gc = 0; 

int main(){
    srand(time(NULL));
    int choice;

    printf("\n\t\t\t>> NUMBER GUESSING GAME << \n\t[(********************************************************)]\n\n" 
    "    Can you guess the number i will be picking randomly between 1 - 100?\n"
    "\n\t\t       [1] PLAY \t\t[0] EXIT");
    printf("\n\nSo? ");

    if (scanf("%d", &choice) == 0){
        inputDetection();
        choice = -1;
    }
    switch (choice){
        case 1: play();
                break;
        default: break;
    }

    otherOption();
    return 0;
}
void play(){
    gc = 0; 
    int compuNum = 0;
    int userG;
    int userCount = 0; 

    char status[20]; // Our string buffer

        strcpy(status, "Hmmmmm... ");
        printf("\r%s", status);
        fflush(stdout);
        for (volatile int d = 0; d < 100000000; d++); // Delay

        strcpy(status, "Almost there...");
        printf("\r%s", status);
        fflush(stdout);
        for (volatile int d = 0; d < 100000000; d++); // Delay

        strcpy(status, "DONE! I already picked a number!      ");
        printf("\r%s\n", status);
        
        compuNum = rand() % 100 + 1;   
        printf("\n(%d)", compuNum); 
        printf("\n\tHow about you?");        
        userG = guess();

        clear();
        evaluator(userG, compuNum);
        userCount = guessCount();

        printf("\n----------------------\n| Your # of Guesses: %d |",userCount);
        printf("\n----------------------");
}

int guess(){
    int a; 
    printf("\n ___________");
    printf("\n| Guess: ");
    if (scanf("%d", &a) == 0){
        inputDetection();
        return guess();
    }
    printf(" ------------");
    guessCount();
    
    return a;
}

void evaluator(int g, int const c){
    int otherGuess;

    if (g == c){
        printf("\nYOU GOT IT RIGHT!! >.<\n");
        return;
    }
    
    if (g > 100){
        printf("\nThat's larger than 100....hmmmm\nOnly between 1-100\n");
    }
    else if (g > c){
        printf("\nLower\n");
    }
    else if (g < c){
        printf("\nHigher\n");
    }
    
    printf("Try Again :P \n");
    otherGuess = guess();
    evaluator(otherGuess, c); // Tail recursion handles the looping safely
}


void inputDetection(){
    int c;
    printf("Error: Invalid Input...");
    while((c = getchar()) != '\n' && c != EOF);
}

void clear(){ // clear terminal with OS support
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int guessCount(){
    gc++;
    return gc;
}

void otherOption(){
    int choice; 
    printf("\n\n    still want to play?" "\n\t\t       [1] PLAY \t\t[0] EXIT\n");
    printf("\nSo? ");
    scanf("%d", &choice); 

    switch (choice){
        case 1: play();
                break;
        case 0: printf("\nOk Bbye!! <3 >\n");
                break;
        default: break;
    }
}