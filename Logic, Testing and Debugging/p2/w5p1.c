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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

#include <stdio.h>

int main(void)
{
    const int JAN = 1, DEC = 12;
    int nYear, nMonth = 0, nDays=1, i;
    double morningRate[LOG_DAYS], eveningRate[LOG_DAYS];
    int done= 0;

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
                if(nMonth == 1)
                {
                    
                printf ("\n*** Log date set! ***\n");
                for(i = 0; i > LOG_DAYS; i++)
                {
                nDays = nDays + i;
                printf("\nLog starting date: %d-JAN-0%d\n", nYear, nDays);
                printf("Morning rating (0.0-5.0): ");
                scanf(" %lf", &morningRate[i]);
                if (morningRate[i] > 0 && morningRate[i] < 5 )
                {
                    printf("\nEvening rating (0.0-5.0):");
                    scanf("% lf", &eveningRate);
                    
                }
                }
                if(i > LOG_DAYS)

                done = 1;
                }
                else if(nMonth == 2)
                {
                printf ("\n*** Log date set! ***\n");
                printf("\nLog starting date: %d-FEB-0%d\n", nYear, nDays);
                done = 1;
                }
                else if(nMonth == 3)
                {
                printf ("\n*** Log date set! ***\n");
                printf("\nLog starting date: %d-MAR-0%d\n", nYear, nDays);
                done = 1;
                }
                else if(nMonth == 4)
                {
                printf ("\n*** Log date set! ***\n");
                printf("\nLog starting date: %d-APR-0%d\n", nYear, nDays);
                done = 1;
                }
                else if(nMonth == 5)
                {
                printf ("\n*** Log date set! ***\n");
                printf("\nLog starting date: %d-MAY-0%d\n", nYear, nDays);
                done = 1;
                }
                else if(nMonth == 6)
                {
                printf ("\n*** Log date set! ***\n");
                printf("\nLog starting date: %d-JUN-0%d\n", nYear, nDays);
                done = 1;
                }
                else if(nMonth == 7)
                {
                printf ("\n*** Log date set! ***\n");
                printf("\nLog starting date: %d-JUL-0%d\n", nYear, nDays);
                done = 1;
                }
                else if(nMonth == 8)
                {
                printf ("\n*** Log date set! ***\n");
                printf("\nLog starting date: %d-AUG-0%d\n", nYear, nDays);
                done = 1;
                }
                else if(nMonth == 9)
                {
                printf ("\n*** Log date set! ***\n");
                printf("\nLog starting date: %d-SEP-0%d\n", nYear, nDays);
                done = 1;
                }
                else if(nMonth == 10)
                {
                printf ("\n*** Log date set! ***\n");
                printf("\nLog starting date: %d-OCT-0%d\n", nYear, nDays);

                done = 1;
                }
                else if(nMonth == 11)
                {
                printf ("\n*** Log date set! ***\n");
                printf("\nLog starting date: %d-NOV-0%d\n", nYear, nDays);
                done = 1;
                }
                else if(nMonth == 12)
                {
                printf ("\n*** Log date set! ***\n");
                printf("\nLog starting date: %d-DEC-0%d\n", nYear, nDays);
                done = 1;
                }
            }
            else if (nMonth > 12 || nMonth < 1)
            {
                printf("   ERROR: Jan.(1) - Dec.(12)");
            }
        }
        else if ((nYear < MIN_YEAR && nYear > 0) || nYear > MAX_YEAR)
        {
        printf("   ERROR: The year must be between 2012 and 2022 inclusive");
        if (nMonth < JAN || nMonth > DEC )
            {
            printf("\n   ERROR: Jan.(1) - Dec.(12)");
            }
        }
        else if (nYear == 0 && nMonth == 0)
        {
            done = 1;
        }
        


    }while (done != 1 );

    done = 0;


    
    return 0;
}