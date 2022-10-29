/*
*****************************************************************************
                        Assignment 1 - Milestone 1
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca
Section    :IPC144NKK

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include "core.h"



int inputInt(void)
{
    int value, keeptrying = 1, rc;
    char after;

    do {
        rc = scanf("%d%c", &value, &after);

        if (rc == 0){
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if (after != '\n'){
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else {
            keeptrying = 0;
        }
    } while (keeptrying == 1);
    
    return value;
}


int inputIntPositive(void)
{
    int value, keeptrying = 1, rc;
    char after;

    do {
        rc = scanf("%d%c", &value, &after);

        if (rc == 0) {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if (after != '\n') {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if (value <= 0) {
            printf("ERROR! Value must be > 0: ");
        }
        else {
            keeptrying = 0;
        }
    } while (keeptrying == 1);

    return value;
}

int inputIntRange(int lower, int upper)
{
    int keeptrying = 1;
    int value;
    char after;
    do {
      scanf("%d%c", &value, &after);

      if (after != '\n') {
          printf("Error! Input a whole number: ");
          clearInputBuffer();
      }
      else if (value > upper || value < lower) {
          printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
      }
      if (value >= lower && value <= upper) {
          keeptrying = 0;
      }
    }while (keeptrying == 1);

    return value;
}

char inputCharOption(const char validChars[])
{  
    int i = 0;
    int exit = 1;
    char letter;
    do {
        scanf("%c", &letter);
        clearInputBuffer();

        exit = 1;
        i = 0;
        while (validChars[i] != '\0' && exit == 1)
        {
            if (letter == validChars[i])
            {
                exit = 0;
            }
            i++;
        }

        if (exit == 1) {
            printf("ERROR: Character must be one of [%s]: ", validChars);
        }

    } while (exit == 1);

    return letter;
}

void inputCString(char* word,int min ,int max)
{
    int length = 0, exit = 1, i = 0;
    char words[100];
    do {
       scanf("%[^\n]s", words);
       clearInputBuffer();

       length = 0;
       while (words[length] != '\0')
       {
           length++;
       }

       //printf("%d", length);
        if ((length < min || length > max) && (max == min)){
                printf("ERROR: String length must be exactly %d chars: ",max);
        }
        else if (length > max) {
                printf("ERROR: String length must be no more than %d chars: ", max);
        }
        else if (length < min) {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);;
        }
        else {
            exit = 0;
        }
    } while (exit == 1 && (length < min || length > max));
    while (words[i] != '\0')
    {
        word[i] = words[i];
        i++;
    }
    word[i] = '\0';
}

void displayFormattedPhone(char *Number)
{
    int length = 0, check = 0, counter = 0;
    int i = 0;
    if (Number != NULL) {
        while (Number[length] != '\0') {
            check = isdigit(Number[length]);
            if (check == 0) {
                counter++;
            }
            length++;
        }
        if (counter > 0 || length != 10) {
            printf("(___)___-____");
        }
        else {
            printf("(");
            for (i = 0; i < length; i++)
            {
                if (i == 3) {
                    printf(")");
                }
                else if (i == 6) {
                    printf("-");
                }
                printf("%c", Number[i]);
            }
        }
    }  
    else {
        printf("(___)___-____");
    }

    
}

// As demonstrated in the course notes: 
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}
