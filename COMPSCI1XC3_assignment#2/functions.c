#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "constants.h"
#include "functions.h"
bool playWordGuessingGame(const char *randomWord)
{
    char guess; // holds currently guessed character
    int length_of_randomWord = strlen(randomWord);
    char guessed[length_of_randomWord]; // this will hold what the user has guessed of the word so far
    // strcpy and the for loop initialize guesses as dashes, as they have guessed nothing yet
    strcpy(guessed, randomWord);
    for (int i = 0; guessed[i] != '\0'; i++)
    {
        guessed[i] = '-';
    }
    int attempts = 0;
    bool correct_guess = false; // is true if user's guessed character is in randomWord
    while (attempts < MAX_ATTEMPTS)
    {
        printf("Attempt %d: ", attempts + 1);
        scanf(" %c", &guess);
        // Iterate through each letter in randomWord and see if guessed character is in there
        for (int i = 0; i < length_of_randomWord; i++)
        {
            if (guess == randomWord[i])
            {
                guessed[i] = guess;
                correct_guess += true;
            }
        }
        // compare the so far guessed word to randomWord to see if they are the same
        int compare_answer = strcmp(randomWord, guessed);
        if (compare_answer == 0)
        {
            return true;
        }
        // If guessed character is not in randomWord, print incorrect along with the guessed letters
        if (correct_guess == false)
        {
            printf("%s\n", guessed);
            printf("Incorrect guess. Try again.\n");
            attempts++;
        }
        // If guessed character is in randomWord, print just the updated guessed letters
        else
        {
            printf("%s\n", guessed);
        }
        correct_guess = false;
    }
    //<if the run reaches here it means after MAX_ATTEMPTS...>
    //< the letters are not found, so use return false;>
    return false;
}

bool playWordGuessingGameAutomatic(const char *randomWord, char **words, int numWords, int numSuggestion)
{
    //<the same algorithm in Part A>
    char guess; // holds currently guessed character
    int length_of_randomWord = strlen(randomWord);
    char guessed[length_of_randomWord]; // this will hold what the user has guessed of the word so far
    // strcpy and the for loop initialize guesses as dashes, as they have guessed nothing yet
    strcpy(guessed, randomWord);
    for (int i = 0; guessed[i] != '\0'; i++)
    {
        guessed[i] = '-';
    }
    int attempts = 0;
    bool correct_guess = false; // is true if user's guessed character is in randomWord
    while (attempts <= MAX_ATTEMPTS)
    {
        // On second last attempt, do the following
        if (MAX_ATTEMPTS - 1 == attempts)
        {
            int counter = 0;
            char *possible_words[51];                             // an array holding pointers to max 50 possible words
            memset(possible_words, '\0', sizeof(possible_words)); // initialize to empty array
            for (int i = 0; i < numWords; i++)
            {
                int length_of_dictionary_word = strlen(words[i]);
                int num_guessed_letters = 0; // counts how many letters you have guessed
                int num_letters_matched = 0; // counts how many letters from guessed match with the word
                if (length_of_randomWord == length_of_dictionary_word)
                {
                    for (int j = 0; j < length_of_randomWord; j++)
                    {
                        // this if statement excludes dashes and keep only the correctly guessed letters to compare
                        if (guessed[j] != '-')
                        {
                            num_guessed_letters += 1;
                            if (guessed[j] == words[i][j])
                            {
                                num_letters_matched += 1;
                            }
                        }
                    }
                    // if all correctly guessed letters are in the word, add it as a possibility
                    // as long as we don't already have 50 possibilities
                    if (num_guessed_letters == num_letters_matched)
                    {
                        counter += 1;
                        if (counter <= 50)
                        {
                            possible_words[counter - 1] = words[i];
                            // printf("%s", possible_words[0]);
                        }
                    }
                }
            }
            printf("\nThe number of possible words = %d\n", counter);
            printf("Here is up to the first 50 possible words:\n\n");
            for (int i = 0; possible_words[i] != NULL; i++)
            {
                printf("%s, ", possible_words[i]);
            }
            printf("\n\n");
            // Last attempt code below
            printf("Attempt %d: ", attempts + 1);
            scanf("%s", &guessed[0]); // user inputs the word they guess
            // Compare the guessed word to the actual word
            int compare_answer = strcmp(randomWord, guessed);
            if (compare_answer == 0)
            {
                return true;
            }
            else
            {
                attempts++;
                return false;
            }
        }
        else
        {
            //<same code as Algorithm A>
            printf("Attempt %d: ", attempts + 1);
            scanf(" %c", &guess);
            // Iterate through each letter in randomWord and see if guessed character is in there
            for (int i = 0; i < length_of_randomWord; i++)
            {
                if (guess == randomWord[i])
                {
                    guessed[i] = guess;
                    correct_guess += true;
                }
            }
            // compare the so far guessed word to randomWord to see if they are the same
            int compare_answer = strcmp(randomWord, guessed);
            if (compare_answer == 0)
            {
                return true;
            }
            // If guessed character is not in randomWord, print incorrect along with the guessed letters
            if (correct_guess == false)
            {
                printf("%s\n", guessed);
                printf("Incorrect guess. Try again.\n");
                attempts++;
            }
            // If guessed character is in randomWord, print just the updated guessed letters
            else
            {
                printf("%s\n", guessed);
            }
            correct_guess = false;
        }
    }
}