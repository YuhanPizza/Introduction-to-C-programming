/*
*****************************************************************************
                          Workshop - #6 (P1)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :lorenzalvintubo@gmail.com or ltubo@myseneca.ca
Section    :IPC144NKK

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN_ITEM 1
#define MAX_ITEM 10

int main(void)
{
    const double max_Income = 400000.00;
    const double min_Income = 500.00;
    const double minPrice = 100.00;
    int importance[MAX_ITEM], i;
    char financing[MAX_ITEM];
    int done = 0;
    double monthlyIncome, total;
    double price[MAX_ITEM];
    int numberofItems;
    printf("+--------------------------+");
    printf("\n+   Wish List Forecaster   |");
    printf("\n+--------------------------+");

    do
    {
        printf("\n\nEnter your monthly NET income: $");
        scanf(" %lf", &monthlyIncome);
        if (monthlyIncome >= min_Income && monthlyIncome <= max_Income)
        {
            do
            {
                printf("\nHow many wish list items do you want to forecast?: ");
                scanf(" %d", &numberofItems);

                if (numberofItems <= MAX_ITEM && numberofItems >= MIN_ITEM)
                {
                    done = 1;
                }
                else if (numberofItems > MAX_ITEM || numberofItems < MIN_ITEM)
                {
                    printf("ERROR: List is restricted to between 1 and 10 items.\n");
                }
            } while (done == 0);
        }
        if (monthlyIncome < min_Income)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00");
        }
        if (monthlyIncome > max_Income)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00");
        }
    } while (done == 0);
    done = 0;

    for (i = 0; i < numberofItems; i++)
    {
        done = 0;
        printf("\nItem-%d Details:", i + 1);
        do
        {
            printf("\n   Item cost: $");
            scanf(" %lf", &price[i]);
            if (price[i] >= minPrice)
            {
                do
                {
                    printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
                    scanf(" %d", &importance[i]);
                    if (importance[i] >= 1 && importance[i] <= 3)
                    {
                        do
                        {
                            printf("   Does this item have financing options? [y/n]: ");
                            scanf(" %c", &financing[i]);
                            if (financing[i] == 'y' || financing[i] == 'n')
                            {
                                done = 1;
                            }
                            else
                            {
                                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                            }
                        } while (done == 0);
                    }
                    else if (importance[i] > 3 || financing[i] < 1)
                    {
                        printf("      ERROR: Value must be between 1 and 3\n");
                    }
                } while (done == 0);
            }
            else if (price[i] < minPrice)
            {
                printf("      ERROR: Cost must be at least $100.00");
            }

        } while (done == 0);
    }

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < numberofItems; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, importance[i], financing[i], price[i]);
        total += price[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", total);

printf("How do you want to forecast your wish list?");
printf("")

    return 0;
}