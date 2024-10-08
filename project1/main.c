#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool start_stop = true;

void ExitProgram() {
    char yes_no;
    printf("\n\nYou sure you want to end the program?\n[type to affirm 'Y']: ");
    scanf(" %c", &yes_no);
    if (yes_no == 'Y' || yes_no == 'y') {
        printf("This is the end of the program.\n");
        start_stop = false;
    }
}

int main() {
    while (start_stop) {
        int user_choice;
        printf("\tThe Options:\n");
        printf("\t1. Hangman game\n");
        printf("\t2. Basic Arithmetic Calculation\n");
        printf("\t3. Word Count\n");
        printf("\t4. Exit Program\n");
        printf("Please Enter Your Input: ");
        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                system("hangman"); // Call Hangman executable
                break;
            case 2:
                system("math"); // Call Math executable
                break;
            case 3:
                system("word_count"); // Call Word Count executable
                break;
            case 4:
                ExitProgram();
                break;
            default:
                printf("\n\nInvalid Input! Please Enter Again\n");
        }
    }
    return 0;
}
