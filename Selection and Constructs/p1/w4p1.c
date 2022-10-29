/*
*****************************************************************************
                          Workshop - #4 (P1)
Full Name  : Lorenz Alvin Tubo
Student ID#: 109934224
Email      : lorenzalvintubo@gmail.com or ltubo@myseneca.ca
Section    : IPC144NKK

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int valueInt, loopMax;
    char loopType;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");
    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &loopMax);

        if (loopType == 'F' && loopMax >= 3 && loopMax <= 20)
        {
            printf("WHILE   :");
            for (valueInt = 1; valueInt <= loopMax; valueInt++)
            {
                printf("F");
            }
            printf("\n\n");
        }
        valueInt = 1;
        if (loopType == 'W' && loopMax >= 3 && loopMax <= 20)
        {
            printf("WHILE   :");
            while (valueInt <= loopMax)
            {
                printf("W");
                valueInt++;
            }
            printf("\n\n");
        }
        valueInt = 1;
        if (loopType == 'D' && loopMax >= 3 && loopMax <= 20)
        {
            printf("WHILE   :");
            do
            {
                printf("D");
            } while (valueInt++ < loopMax);
            printf("\n\n");
        }
        if (loopType == 'D' || loopType == 'W' || loopType == 'F' && loopMax < 3 || loopMax > 20)
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
        }
        else if (loopType == 'Q' && loopMax != 0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
        }
        else if (loopType != 'D' && loopType != 'W' && loopType != 'F' && loopType != 'Q')
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }

    } while (loopType != 'Q' && loopMax != 0);
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}