/*
*****************************************************************************
                          Final Question 1
Contributors  : Lorenzo Alvino Tubo Caballo, Clara Verena Brito Battesini, Fausto Javier Zaruma Arias.
Student ID(s)#: 109934224,143430213,119758217
Emails        : ltubo@senecacollege.ca,cverena-brito-battes@senecacollege.ca,fjzaruma@myseneca.ca
Section       : NKK

Authenticity Declaration:
We declare this submission is the result of our own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of our own creation.
*****************************************************************************
*/

// IPC144 2022 Summer Final Assessment Coding Project
// --------------------------------------------------
// Project idea is based on COSEWIC reports for SAR
//
//      COSEWIC: Committee on the Status of Endangered Wildlife in Canada
//      SAR:     Species At Risk
//
// Source: https://bit.ly/3AEgab9
//
// Note: The data used for this assignment has been fictionalized with invalid counts

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "cosewic.h"

#define DATA_FILE "data.csv"
#define MAX_RECORDS 6500

int main(void)
{
    int records;
    struct FileData data[MAX_RECORDS] = {{0}};

    printf("Loading data from file: %s\n", DATA_FILE);
    records = loadData(DATA_FILE, data, MAX_RECORDS);
    printf("%d data records read from file...\n\n", records);

    if (records > 0)
    {
        // Entry point to application logic
        mainLogic(data, records);
    }
    else
    {
        printf("Ooooops there seems to have been an error loading data!\n");
    }

    return 0;
}
