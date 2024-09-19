#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6 // Maximum wrong attempts allowed

void printWord(char word[], int wordLen, int guessed[]) {
    for (int i = 0; i < wordLen; i++) {
        if (guessed[i])
            printf("%c ", word[i]);
        else
            printf("_ ");
    }
    printf("\n");
}

int isWordGuessed(int guessed[], int wordLen) {
    for (int i = 0; i < wordLen; i++) {
        if (!guessed[i])
            return 0;
    }
    return 1;
}

int main() {
    char word[] = "memaybeo"; // Word to be guessed
    int wordLen = strlen(word);  // Length of the word
    int guessed[wordLen];        // Tracks guessed letters
    int tries = 0;               // Number of incorrect attempts
    int correctGuess = 0;        // Number of correct guesses

    // Initialize guessed array to 0 (false) for each letter in the word
    for (int i = 0; i < wordLen; i++) {
        guessed[i] = 0;
    }

    printf("Welcome to Hangman!\n");

    // Main game loop
    while (tries < MAX_TRIES) {
        printf("\nWord to guess: ");
        printWord(word, wordLen, guessed);

        printf("You have %d tries left.\n", MAX_TRIES - tries);
        printf("Enter a letter: ");

        char guess;
        scanf(" %c", &guess); // Taking input from the user
        guess = tolower(guess); // Ensure lowercase input

        int found = 0; // Flag to check if the letter is in the word

        // Check if the guessed letter is in the word
        for (int i = 0; i < wordLen; i++) {
            if (word[i] == guess && !guessed[i]) {
                guessed[i] = 1;
                found = 1;
                correctGuess++;
            }
        }

        // If guessed letter is not found, increment the number of tries
        if (!found) {
            tries++;
            printf("Incorrect guess!\n");
        } else {
            printf("Correct guess!\n");
        }

        // Check if the whole word has been guessed
        if (isWordGuessed(guessed, wordLen)) {
            printf("\nCongratulations! You've guessed the word: %s\n", word);
            break;
        }
    }

    // If player runs out of tries
    if (tries == MAX_TRIES) {
        printf("\nGame Over! The word was: %s\n", word);
    }

    return 0;
}
