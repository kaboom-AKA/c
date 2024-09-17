#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function Prototypes
void solo_game();
void two_player_game();
void start_game();
void ExitProgram();
void draw_hangman(int mistakes);

// Global Variables
bool start_stop = true;
char Guess_Word[100];              
char hidden_word[100];                 
int letter_count = 0;                  
int mistakes = 7;                      
char user_input[100];                  
char formatted_user_input[26] = "";    
int no_of_different_letters = 0;       

int main() {
    int no_of_players;
    
    while (start_stop) {
        printf("\n1. Solo game \n2. Play with friends\n3. Exit\nEnter your option: ");
        scanf("%d", &no_of_players);
        
        switch (no_of_players) {
            case 1:
                solo_game();
                start_game();
                break;
            case 2:
                two_player_game();
                start_game();
                break;
            case 3:
                ExitProgram();
                break;
            default:
                printf("\n\nInvalid Input! Please Enter Again\n");
        }
    }
    
    return 0;
}

void ExitProgram() {
    char yes_no;
    printf("You sure you want to end the program?\n[type 'Y' to affirm]: ");
    scanf(" %c", &yes_no);  // The space before %c ensures it skips any whitespace
    
    if (yes_no == 'Y' || yes_no == 'y') {  
        printf("\nThis is the end of the program.\n");
        start_stop = false;
    }
}

void solo_game() {
    int topic_choosen;
    FILE *file;
    char line[2048];
    char words[100][100];  // Array to store up to 100 words, each word up to 100 characters long.
    int word_count = 0;

    printf("\n\nSolo game only you and computer\n\n");
    printf("\t1. Animals\n");
    printf("\t2. Geography\n");
    printf("\t3. Fruits and Vegetables\n");
    printf("\t4. Hobbies\n");
    printf("\t5. General\n");
    printf("Enter Your Option :\t");
    scanf("%d", &topic_choosen);

    switch (topic_choosen) {
        case 1:
            file = fopen("words/animals.txt", "r");
            break;
        case 2:
            file = fopen("words/geography.txt", "r");
            break;
        case 3:
            file = fopen("words/fruits_vegetables.txt", "r");
            break;
        case 4:
            file = fopen("words/hobbies.txt", "r");
            break;
        case 5:
            file = fopen("words/general.txt", "r");
            break;
        default:
            printf("\nInvalid Option!\n");
            return;
    }

    if (file) {
        while (fgets(line, sizeof(line), file)) {
            char *token = strtok(line, ", ");
            while (token) {
                strcpy(words[word_count], token);  // Copy the word to the words array.
                word_count++;
                token = strtok(NULL, ", ");
            }
        }
        fclose(file);

        if (word_count > 0) {
            srand(time(NULL)); // Seed the random number generator.
            int random_index = rand() % word_count;  // Get a random index.
            strcpy(Guess_Word, words[random_index]); // Store the randomly selected word in the global Guess_Word variable.
        } else {
            printf("No words found in the file.\n");
        }
    } else {
        printf("Error opening file.\n");
    }
}

void two_player_game() {
    printf("\n\n2 players Hangman game with 1 word setter and 1 guesser\n\n");
    printf("\nWord Setter, enter the guess word: ");
    scanf("%99s", Guess_Word);
}

void start_game() {
    // Reset game state variables
    letter_count = 0;
    mistakes = 7;
    no_of_different_letters = 0;
    memset(formatted_user_input, 0, sizeof(formatted_user_input)); // Clear previous inputs

    for (int i = 0; i < strlen(Guess_Word); i++) {
        Guess_Word[i] = tolower((unsigned char)Guess_Word[i]);
        hidden_word[i] = '_';
    }
    hidden_word[strlen(Guess_Word)] = '\0';

    printf("\n------ The game starts now!! ---------------\n");

    while (mistakes > 0 && letter_count < strlen(Guess_Word)) {
        printf("\nCurrent word: %s\n", hidden_word);
        printf("Guesser, enter your guess [word or letters]: ");
        scanf("%99s", user_input);

        for (int i = 0; i < strlen(user_input); i++) {
            user_input[i] = tolower((unsigned char)user_input[i]);
        }

        for (int i = 0; i < strlen(user_input); i++) {
            int is_unique = 1;

            for (int j = 0; j < strlen(formatted_user_input); j++) {
                if (user_input[i] == formatted_user_input[j]) {
                    is_unique = 0;
                    break;
                }
            }

            if (is_unique) {
                formatted_user_input[no_of_different_letters] = user_input[i];
                no_of_different_letters++;
                formatted_user_input[no_of_different_letters] = '\0';

                int found = 0;
                for (int k = 0; k < strlen(Guess_Word); k++) {
                    if (user_input[i] == Guess_Word[k]) {
                        hidden_word[k] = Guess_Word[k];
                        letter_count++;
                        found = 1;
                    }
                }

                if (!found) {
                    mistakes--;
                    printf("Incorrect guess! Remaining mistakes: %d\n", mistakes);
                }
            }
        }

        draw_hangman(mistakes);
    }

    if (letter_count == strlen(Guess_Word)) {
        printf("\nCongratulations! You've guessed the word: %s\n", Guess_Word);
    } else {
        printf("\nGame over! The word was: %s\n", Guess_Word);
    }
}

void draw_hangman(int mistakes) {
    switch (mistakes) {
        case 7:
            printf("\n\n|----------");
            printf("\n|     |    ");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            break;
        case 6:
            printf("\n\n|----------");
            printf("\n|     |    ");
            printf("\n|   _____  ");
            printf("\n|  |     | ");
            printf("\n|  |_____| ");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            break;
        case 5:
            printf("\n\n|----------");
            printf("\n|     |    ");
            printf("\n|   _____  ");
            printf("\n|  |     | ");
            printf("\n|  |_____| ");
            printf("\n|     |    ");
            printf("\n|     |    ");
            printf("\n|");
            printf("\n|");
            break;
        case 4:
            printf("\n\n|----------");
            printf("\n|     |    ");
            printf("\n|   _____  ");
            printf("\n|  |     | ");
            printf("\n|  |_____| ");
            printf("\n|    /|    ");
            printf("\n|   / |    ");
            printf("\n|");
            printf("\n|");
            break;
        case 3:
            printf("\n\n|----------");
            printf("\n|     |    ");
            printf("\n|   _____  ");
            printf("\n|  |     | ");
            printf("\n|  |_____| ");
            printf("\n|    /|\\   ");
            printf("\n|   / | \\  ");
            printf("\n|");
            printf("\n|");
            break;
        case 2:
            printf("\n\n|----------");
            printf("\n|     |    ");
            printf("\n|   _____  ");
            printf("\n|  |     | ");
            printf("\n|  |_____| ");
            printf("\n|    /|\\   ");
            printf("\n|   / | \\  ");
            printf("\n|    /     ");
            printf("\n|   /      ");
            break;
        case 1:
            printf("\n\n|----------");
            printf("\n|     |    ");
            printf("\n|   _____  ");
            printf("\n|  |     | ");
            printf("\n|  |_____| ");
            printf("\n|    /|\\   ");
            printf("\n|   / | \\  ");
            printf("\n|    / \\   ");
            printf("\n|   /   \\  ");
            break;
        case 0:
            printf("\n\n|----------");
            printf("\n|     |    ");
            printf("\n|   _____  ");
            printf("\n|  |     | ");
            printf("\n|  |_____| ");
            printf("\n|    /|\\   ");
            printf("\n|   / | \\  ");
            printf("\n|    / \\   ");
            printf("\n|   /   \\  ");
            printf("\n|");
            break;
    }
}
