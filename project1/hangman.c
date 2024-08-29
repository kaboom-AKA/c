#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool start_stop = true;

void solo_game();
void two_player_game();
void ExitProgram();

int main()
{
    int no_of_players;
    
    while (start_stop)
    {
        printf("\n1. Solo game \n2. Play with friends\n3. Exit\nEnter your option: ");
        scanf("%d", &no_of_players);
        
        switch (no_of_players)
        {
            case 1:
                solo_game();
                break;
            case 2:
                two_player_game();
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

void ExitProgram() 
{
    char yes_no;
    printf("You sure you want to end the program?\n[type 'Y' to affirm]: ");
    scanf(" %c", &yes_no);  // The space before %c ensures it skips any whitespace
    
    if (yes_no == 'Y' || yes_no == 'y') 
    {  
        printf("This is the end of the program.\n");
        start_stop = false;
    }
}

void two_player_game() 
{
    char Guess_Word[100];                  // Word to be guessed
    char hidden_word[100];                 // Displayed version with hidden letters
    int letter_count = 0;                  // Count of correct letters guessed
    int mistakes = 7;                      // Number of allowed mistakes
    char user_input[100];                  // User's guess input
    char formatted_user_input[26] = "";    // Unique guessed letters
    int no_of_different_letters = 0;       // Counter for unique guessed letters

    printf("\n\n2 players Hangman game with 1 word setter and 1 guesser\n\n");
    printf("\nWord Setter, enter the guess word: ");
    scanf("%99s", Guess_Word);

    for (int i = 0; i < strlen(Guess_Word); i++) 
    {
        Guess_Word[i] = tolower((unsigned char)Guess_Word[i]);
        hidden_word[i] = '_';
    }
    hidden_word[strlen(Guess_Word)] = '\0';

    printf("\n------ The game starts now!! ---------------\n");

    while (mistakes > 0 && letter_count < strlen(Guess_Word)) 
    {
        printf("\nCurrent word: %s\n", hidden_word);
        printf("Guesser, enter your guess [word or letters]: ");
        scanf("%99s", user_input);

        for (int i = 0; i < strlen(user_input); i++) 
        {
            user_input[i] = tolower((unsigned char)user_input[i]);
        }

        for (int i = 0; i < strlen(user_input); i++) 
        {
            int is_unique = 1;

            for (int j = 0; j < strlen(formatted_user_input); j++) 
            {
                if (user_input[i] == formatted_user_input[j]) 
                {
                    is_unique = 0;
                    break;
                }
            }

            if (is_unique) 
            {
                formatted_user_input[no_of_different_letters] = user_input[i];
                no_of_different_letters++;
                formatted_user_input[no_of_different_letters] = '\0';

                int found = 0;
                for (int k = 0; k < strlen(Guess_Word); k++) 
                {
                    if (user_input[i] == Guess_Word[k]) 
                    {
                        hidden_word[k] = Guess_Word[k];
                        letter_count++;
                        found = 1;
                    }
                }

                if (!found) 
                {
                    mistakes--;
                    printf("Incorrect guess! Remaining mistakes: %d\n", mistakes);
                }
            }
        }

        switch (mistakes)
        {
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
                printf("\n|    /|\\  ");
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
                printf("\n|    /|\\  ");
                printf("\n|   / | \\ ");
                printf("\n|    /     ");
                printf("\n|   /      ");
                break;
            case 1:
                printf("\n\n|----------");
                printf("\n|     |    ");
                printf("\n|   _____  ");
                printf("\n|  |     | ");
                printf("\n|  |_____| ");
                printf("\n|    /|\\  ");
                printf("\n|   / | \\ ");
                printf("\n|    / \\  ");
                printf("\n|   /   \\ ");
                break;
            case 0:
                printf("\n\n|----------");
                printf("\n|     |    ");
                printf("\n|   _____  ");
                printf("\n|  |     | ");
                printf("\n|  |_____| ");
                printf("\n|    /|\\  ");
                printf("\n|   / | \\ ");
                printf("\n|    / \\  ");
                printf("\n|   /   \\ ");
                printf("\n|   You have lost! The game is over.");
                break;
            default:
                printf("\nInvalid number of mistakes.\n");
                break;
        }
    }

    if (letter_count == strlen(Guess_Word)) 
    {
        printf("\nCongratulations! You've guessed the word: %s\n", Guess_Word);
    } 
    else 
    {
        printf("\nGame over! The word was: %s\n", Guess_Word);
    }
}

void solo_game()
{
    printf("\n\nSolo game only you and computer\n\n");
}
