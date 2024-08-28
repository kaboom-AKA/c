#include <stdio.h>
#include <stdbool.h> 

// Global variables
int start_stop = 1;

// Function declarations
void Hangman();
void Math();
void Word_count();
void ExitProgram();

int main() {
    while (start_stop == 1) {
        int user_choice;
        printf("\tThe Options:\n\t1. Hangman game\n\t2. Basic Arithmetic Calculation\n\t3. Word Count\n\t4. Exit Program\n");
        printf("Please Enter Your Input: ");
        scanf("%d", &user_choice);  // Use & to pass the address of user_choice
        
        switch(user_choice) {
            case 1:
                Hangman();
                break;
            case 2:
                Math();
                break;
            case 3:
                Word_count();
                break;
            case 4:
                ExitProgram();
                break;
            default:
                printf("Invalid Input! Please Enter Again\n");
                continue;
        }
    }
    return 0;
}

// Placeholder functions
void Hangman() {
    printf("Hangman game selected.\n");
}

void Math() {
    printf("Basic Arithmetic Calculation selected.\n");
}

void Word_count() {
    printf("Word Count selected.\n");
}

void ExitProgram() {
    char yes_no;
    printf("You sure you want to end the program?\n[type to affirm 'Y']: ");
    scanf(" %c", &yes_no);  // Use " %c" with space to handle newline characters
    if (yes_no == 'Y' || yes_no == 'y') {  // Use || for logical OR
        printf("This is the end of the program.\n");
        start_stop = 0;
    }
}