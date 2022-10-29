/*
*****************************************************************************
                          Workshop - #5 (P1)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int nYear, nMonth = 0, nDays, i=1;
    double mRate[LOG_DAYS], eRate[LOG_DAYS];
    printf("General Well-being Log\n");
    printf("======================");
    do
    {
        printf("\nSet the year and month for the well-being log (YYYY MM): ");
        scanf(" %d%d", &nYear, &nMonth);
        if (nYear >= MIN_YEAR && nYear <= MAX_YEAR)
        {
            if (nMonth >= JAN && nMonth <= DEC)
            {
                switch (nMonth)
                {
                case 1:
                    printf("\n*** Log date set! ***\n\nLog starting date: %d-JAN-0%d\n", nYear, nDays);
                    break;
                case 2:
                    printf("\n*** Log date set! ***\n");
                    printf("\nLog starting date: %d-FEB-0%d\n", nYear, nDays);
                    do
                    {
                        printf("\nMorning rating (0.0-5.0): ");
                        scanf(" %lf", &mRate[i]);
                        if (mRate[i] >= 0 && mRate[i] <= 5)
                        {
                            printf("\nEvening rating (0.0-5.0): ");
                            scanf(" %lf", &eRate[i]);
                            if (eRate[i] >= 0 && eRate[i] <= 5)
                            {
                                printf("%d\n", i);
                                nDays = nDays + 1;
                                i++;
                            }
                            else if (eRate[i] > 5 || eRate[i] < 0)
                            {
                                printf("\nInsufficient Evening Rate");
                            }
                            
                        }
                        else if (mRate[i] < 5 || mRate[i] > 0)
                            {
                                printf("\nInsufficient Morning RATE");
                            }
                    }while (i < LOG_DAYS);
                        break;
                    case 3:
                        printf("\n*** Log date set! ***\n\nLog starting date: %d-MAR-0%d\n", nYear, nDays);
                        break;
                    case 4:
                        printf("\n*** Log date set! ***\n\nLog starting date: %d-APR-0%d\n", nYear, nDays);
                        break;
                    case 5:
                        printf("\n*** Log date set! ***\n\nLog starting date: %d-MAY-0%d\n", nYear, nDays);
                        break;
                    case 6:
                        printf("\n*** Log date set! ***\n\nLog starting date: %d-JUN-0%d\n", nYear, nDays);
                        break;
                    case 7:
                        printf("\n*** Log date set! ***\n\nLog starting date: %d-JUL-0%d\n", nYear, nDays);
                        break;
                    case 8:
                        printf("\n*** Log date set! ***\n\nLog starting date: %d-AUG-0%d\n", nYear, nDays);
                        break;
                    case 9:
                        printf("\n*** Log date set! ***\n\nLog starting date: %d-SEP-0%d\n", nYear, nDays);
                        break;
                    case 10:
                        printf("\n*** Log date set! ***\n\nLog starting date: %d-OCT-0%d\n", nYear, nDays);
                        break;
                    case 11:
                        printf("\n*** Log date set! ***\n\nLog starting date: %d-NOV-0%d\n", nYear, nDays);
                        break;
                    case 12:
                        printf("\n*** Log date set! ***\n\nLog starting date: %d-DEC-0%d\n", nYear, nDays);
                        break;
                    }
                }
                else
                {
                    printf("   ERROR: Jan.(1) - Dec.(12)");
                }
            }
            else if ((nYear < MIN_YEAR) || (nYear > MAX_YEAR))
            {
                printf("   ERROR: The year must be between 2012 and 2022 inclusive");

                if ((nMonth < 1) || (nMonth > 12))
                {
                    printf("\n   ERROR: Jan.(1) - Dec.(12)");
                }
            }
    }while (nYear < MIN_YEAR || nYear > MAX_YEAR || nMonth < 1 || nMonth > 12)
        
            ;

        /*for (i = 0; i < LOG_DAYS; i++)
        {
            printf("Morning Ratings %lf\n", mRate[i]);
            printf("Evening Ratings %lf\n", eRate[i]);
        }*/

return 0;
}