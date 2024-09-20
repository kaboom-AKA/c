#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Global variables
bool start_stop = true;
int letter_count[26] = {0};  // Array to track count of each letter (a-z)
char word_array[500][45];    // Array to store words
int word_count = 0, sentence_count = 0, total_letters = 0;

// Function declarations
void ExitProgram(void);
void process_paragraph(char *paragraph);

int main() {
    while (start_stop) 
    {
        char paragraph[1000];
        printf("Type in a paragraph (letters, punctuations, and spaces only).\nAny other characters will exit the program:\n");
        fgets(paragraph, sizeof(paragraph), stdin);  // Reading entire paragraph

        // Check for invalid characters
        for (int i = 0; paragraph[i] != '\0'; i++) {
            if (!isalnum(paragraph[i]) && !ispunct(paragraph[i]) && !isspace(paragraph[i])) {
                printf("Invalid input detected! Exiting the program.\n");
                start_stop = false;
                return 0;
            }
        }

        process_paragraph(paragraph);  // Process the paragraph to count words, letters, etc.

        // Ask the user if they want to continue or exit
        ExitProgram();
    }

    return 0;
}

void process_paragraph(char *paragraph)
{
    char *word;
    bool in_word = false;
    int word_idx = 0, letter_idx = 0;

    for (int i = 0; paragraph[i] != '\0'; i++) 
    {
        char ch = paragraph[i];

        // Count sentences based on common end punctuation
        if (ch == '.' || ch == '!' || ch == '?') {
            sentence_count++;
        }

        // Count letters and track their frequency
        if (isalpha(ch)) {
            total_letters++;
            letter_count[tolower(ch) - 'a']++;  // Convert to lowercase and update frequency
            in_word = true;
        }

        // Count words (whenever you encounter a space or punctuation after a word)
        if (isspace(ch) || ispunct(ch)) {
            if (in_word) {
                word_idx++;
                in_word = false;
            }
        }
    }

    printf("\nTotal letters: %d\n", total_letters);
    printf("Total sentences: %d\n", sentence_count);
    printf("Total words: %d\n", word_idx);
    
    // Find the most frequent letter
    int max_count = 0;
    char most_freq_letter = 'a';
    for (int i = 0; i < 26; i++) {
        if (letter_count[i] > max_count) {
            max_count = letter_count[i];
            most_freq_letter = i + 'a';  // Convert back to letter
        }
    }

    printf("Most frequent letter: '%c' with %d occurrences\n", most_freq_letter, max_count);
}

void ExitProgram() 
{
    char yes_no;
    printf("\nYou sure you want to end the program? [type 'Y' to affirm]: ");
    scanf(" %c", &yes_no);  
    if (yes_no == 'Y' || yes_no == 'y') {  
        printf("This is the end of the program.\n");
        start_stop = false;
    }
    else {
        // Clear the input buffer before accepting new input
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
}
