/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : 
Student ID#:
Email      :
Section    :

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
    int done = 0;
    do
    {
        int apples = 0, oranges = 0, pears = 0, tomatoes = 0, cabbages = 0;
        int applesPicked = 0, orangesPicked = 0, pearsPicked = 0, tomatoesPicked = 0, cabbagesPicked = 0;
        int Total;

        printf("Grocery Shopping\n");
        printf("================\n");
        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);

            if (apples >= 0)
            {
                printf("\n");
                do
                {
                    printf("How many ORANGES do you need? : ");
                    scanf("%d", &oranges);
                    if (oranges >= 0)
                    {
                        printf("\n");
                        do
                        {
                            printf("How many PEARS do you need? : ");
                            scanf("%d", &pears);
                            if (pears >= 0)
                            {
                                printf("\n");
                                do
                                {
                                    printf("How many TOMATOES do you need? : ");
                                    scanf("%d", &tomatoes);
                                    if (tomatoes >= 0)
                                    {
                                        printf("\n");
                                        do
                                        {

                                            printf("How many CABBAGES do you need? : ");
                                            scanf("%d", &cabbages);
                                            if (cabbages <= -1)
                                            {
                                                printf("ERROR: Value must be 0 or more.\n");
                                            }
                                        } while (cabbages < 0);
                                    }
                                    else if (tomatoes <= -1)
                                    {
                                        printf("ERROR: Value must be 0 or more.\n");
                                    }
                                } while (tomatoes < 0);
                            }
                            else if (pears <= -1)
                            {
                                printf("ERROR: Value must be 0 or more.\n");
                            }
                        } while (pears < 0);
                    }
                    else if (oranges <= -1)
                    {
                        printf("ERROR: Value must be 0 or more.\n");
                    }
                } while (oranges < 0);
            }
            else if (apples <= -1)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (apples < 0);

        printf("\n");
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");
        if (apples > 0)
        {
            do
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &applesPicked);

                if (applesPicked <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (applesPicked > apples)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", apples - Total);
                }
                if (applesPicked >= 1 && applesPicked <= apples)
                {
                    Total = Total + applesPicked;
                    if (Total != apples)
                    {
                        printf("Looks like we still need some APPLES...\n");
                    }
                }
                applesPicked = 0;

            } while (Total != apples);
            if (apples == Total && apples > 0)
            {
                printf("Great, that's the apples done!\n\n");
            }
        }
        Total = 0;

        if (oranges > 0)
        {
            do
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &orangesPicked);

                if (orangesPicked <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (orangesPicked > oranges)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges - Total);
                }
                if (orangesPicked >= 1 && orangesPicked <= oranges)
                {
                    Total = Total + orangesPicked;
                    if (Total != oranges)
                    {
                        printf("Looks like we still need some ORANGES...\n");
                    }
                }
                orangesPicked = 0;

            } while (Total != oranges);
            if (oranges == Total && oranges > 0)
            {
                printf("Great, that's the oranges done!\n\n");
            }
        }
        Total = 0;
        if (pears > 0)
        {
            do
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pearsPicked);

                if (pearsPicked <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pearsPicked > pears)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pears - Total);
                }
                if (pearsPicked >= 1 && pearsPicked <= pears)
                {
                    Total = Total + pearsPicked;
                    if (Total != pears)
                    {
                        printf("Looks like we still need some PEARS...\n");
                    }
                }
                pearsPicked = 0;

            } while (Total != pears);
            if (pears == Total && pears > 0)
            {
                printf("Great, that's the pears done!\n\n");
            }
        }
        Total = 0;
        if (tomatoes > 0)
        {
            do
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &tomatoesPicked);

                if (tomatoesPicked <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (tomatoesPicked > tomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes - Total);
                }
                if (tomatoesPicked >= 1 && tomatoesPicked <= tomatoes)
                {
                    Total = Total + tomatoesPicked;
                    if (Total != tomatoes)
                    {
                        printf("Looks like we still need some TOMATOES...\n");
                    }
                }
                tomatoesPicked = 0;

            } while (Total != tomatoes);
            if (tomatoes == Total && tomatoes > 0)
            {
                printf("Great, that's the tomatoes done!\n\n");
            }
        }
        Total = 0;
        if (cabbages > 0)
        {
            do
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &cabbagesPicked);

                if (cabbagesPicked <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (cabbagesPicked > cabbages)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages - Total);
                }
                if (cabbagesPicked >= 1 && cabbagesPicked <= cabbages)
                {
                    Total = Total + cabbagesPicked;
                    if (Total != cabbages)
                    {
                        printf("Looks like we still need some CABBAGES...\n");
                    }
                }
                cabbagesPicked = 0;

            } while (Total != cabbages);
            if (cabbages == Total && cabbages > 0)
            {
                printf("Great, that's the cabbages done!\n\n");
            }
        }
        Total = 0;
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &done);
        printf("\n");
    } while (done != 0);
    printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}