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
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "cosewic.h"

void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Input valid int value

int inputInt(void)
{
    char isBreackLine;
    int value, wasTyped, done = 1;

    while (done)
    {
        wasTyped = scanf(" %d%c", &value, &isBreackLine);

        if (wasTyped == 0)
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if (isBreackLine != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else
        {
            done = 0;
        }
    }

    return value;
};

// Input valid positive int value
int inputIntPositive(void)
{
    int input, done = 1;

    while (done)
    {
        input = inputInt();
        if (input > 0)
        {
            done = 0;
        }
        else
        {
            printf("ERROR! Value must be > 0: ");
        }
    }
    return input;
};

int loadData(const char *datafile, struct FileData data[], int max)
{
    int i = 0, count = 0, rc;
    FILE *fp = NULL;

    fp = fopen(datafile, "r");

    if (fp != NULL)
    {
        fscanf(fp, "%*[^\n]");
        while (i < max)
        {
            rc = fscanf(fp, "%4d,%[^,],%[^,],%2d,%[^\n]", &data[i].year, data[i].taxon, data[i].status, &data[i].count, data[i].province);

            if (rc > 0)
            {
                count++;
            }
            i++;
        }
        fclose(fp);
    }
    return count;
};

// Input valid positive int value
int inputIntRange(int lower, int upper)
{
    int keeptrying = 1;
    int value;
    char after;

    do
    {
        scanf("%d%c", &value, &after);
        if (after != '\n')
        {
            printf("\nInvalid menu selection!\n");
        }
        else if (value > upper || value < lower)
        {
            printf("\nInvalid menu selection!\n");
        }
        if (value >= lower && value <= upper)
        {
            keeptrying = 0;
        }
        keeptrying = 0;
    } while (keeptrying == 1);
    return value;
}

// VIEW FUNCTIONS
// View by province and taxon
void viewByProvAndTax(struct FileData data[], int max, struct Provinces province[], struct Taxon taxon[])
{
    int selectProvince, selectionTaxon;
    int ext = 0, extir = 0, end = 0, threat = 0, con = 0, total = 0;

    do
    {
        printf("Choose a Province\n");
        printf("----------------------------------\n");
        for (int i = 0; i < PROVINCE_AMOUNT; i++)
        {
            printf("%2d) %s (%s)\n", i + 1, province[i].abbreviation, strcmp(province[i].province, "Northwest Territory") == 0 ? "Northwest Territories" : province[i].province);
        }
        printf("Selection: ");
        selectProvince = inputIntRange(1, PROVINCE_AMOUNT);
        printf("\n");
    } while (selectProvince < 1 || selectProvince > PROVINCE_AMOUNT);

    do
    {
        printf("Choose a Taxon\n");
        printf("---------------\n");
        for (int j = 0; j < TAXON_AMOUNT; j++)
        {
            printf("%2d) %s\n", j + 1, taxon[j].species);
        }
        printf("Selection: ");
        selectionTaxon = inputIntRange(1, TAXON_AMOUNT);
        printf("\n");
    } while (selectionTaxon > TAXON_AMOUNT || selectionTaxon < 1);

    for (int k = 0; k < max; k++)
    {
        if ((strcmp(data[k].province, province[selectProvince - 1].abbreviation) == 0) && (strcmp(data[k].taxon, taxon[selectionTaxon - 1].species) == 0))
        {
            if (strcmp(data[k].status, "EXTINCT") == 0)
            {
                ext += data[k].count;
            }
            else if (strcmp(data[k].status, "EXTIRPATED") == 0)
            {
                extir += data[k].count;
            }
            else if (strcmp(data[k].status, "ENDANGERED") == 0)
            {
                end += data[k].count;
            }
            else if (strcmp(data[k].status, "THREATENED") == 0)
            {
                threat += data[k].count;
            }
            else if (strcmp(data[k].status, "SPECIAL CONCERN") == 0)
            {
                con += data[k].count;
            }
            total += data[k].count;
        }
    }
    printf("*** Data filtered by PROVINCE and TAXON ***\n\n");
    printf("    Province: %s\n", province[selectProvince - 1].province);
    printf("    Taxon   : %s\n", taxon[selectionTaxon - 1].species);

    printf("\nEXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
    printf("------- ---------- ---------- ---------- ------- ---------\n");
    printf("    %03d        %03d        %03d        %03d     %03d      %04d\n\n", ext, extir, end, threat, con, total);
}

// VIEW BY TAXON
void initializationOfTaxon(struct FileData data[], int max, struct Taxon taxon[])
{

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < TAXON_AMOUNT; j++)
        {
            if (strcmp(data[i].taxon, taxon[j].species) == 0)
            {
                if (strcmp(data[i].status, "EXTINCT") == 0)
                {
                    taxon[j].extinct += data[i].count;
                }
                else if (strcmp(data[i].status, "EXTIRPATED") == 0)
                {
                    taxon[j].extirpated += data[i].count;
                }
                else if (strcmp(data[i].status, "ENDANGERED") == 0)
                {
                    taxon[j].endangered += data[i].count;
                }
                else if (strcmp(data[i].status, "THREATENED") == 0)
                {
                    taxon[j].threatened += data[i].count;
                }
                else if (strcmp(data[i].status, "SPECIAL CONCERN") == 0)
                {
                    taxon[j].concern += data[i].count;
                }
                taxon[j].total += data[i].count;
            }
        }
    }
}

void viewByTaxonAsc(struct Taxon taxon[], int max)
{
    int sumExt = 0, sumExtrd = 0, sumEnd = 0, sumThr = 0, sumConc = 0, sumTotal = 0;
    int sortedIndexes[14] = {0};
    int temp = 0;
    int i, j;

    printf("TAXON           EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
    printf("--------------- ------- ---------- ---------- ---------- ------- ---------\n");

    for (int i = 0; i < max; i++)
    {
        sortedIndexes[i] = taxon[i].total;
    }

    for (i = 0; i < max; ++i)
    {
        for (j = 0; j < max - 1 - i; ++j)
        {
            if (sortedIndexes[j] > sortedIndexes[j + 1])
            {
                temp = sortedIndexes[j + 1];
                sortedIndexes[j + 1] = sortedIndexes[j];
                sortedIndexes[j] = temp;
            }
        }
    }

    j = 0;
    for (int i = 0; i < max; i++)
    {
        while (j != max)
        {
            if (taxon[i].total == sortedIndexes[j])
            {
                printf("%-15s    %04d       %04d       %04d       %04d    %04d     %05d\n", taxon[i].species, taxon[i].extinct, taxon[i].extirpated, taxon[i].endangered, taxon[i].threatened, taxon[i].concern, taxon[i].total);
                j++;
                i = -1;
            }
            i++;
        }

        sumExt += taxon[i].extinct;
        sumExtrd += taxon[i].extirpated;
        sumEnd += taxon[i].endangered;
        sumThr += taxon[i].threatened;
        sumConc += taxon[i].concern;
        sumTotal += taxon[i].total;
    }

    printf("                ------- ---------- ---------- ---------- ------- ---------\n");
    printf("                  %05d      %05d      %05d      %05d   %05d    %06d\n\n", sumExt, sumExtrd, sumEnd, sumThr, sumConc, sumTotal);
}

// VIEW BY PROVINCE
void initalizationOfProv(struct FileData data[], int max, struct Provinces province[])
{
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < PROVINCE_AMOUNT; j++)
        {
            if (strcmp(data[i].province, province[j].abbreviation) == 0)
            {
                if (strcmp(data[i].status, "EXTINCT") == 0)
                {
                    province[j].extinct += data[i].count;
                }
                else if (strcmp(data[i].status, "EXTIRPATED") == 0)
                {
                    province[j].extirpated += data[i].count;
                }
                else if (strcmp(data[i].status, "ENDANGERED") == 0)
                {
                    province[j].endangered += data[i].count;
                }
                else if (strcmp(data[i].status, "THREATENED") == 0)
                {
                    province[j].threatened += data[i].count;
                }
                else if (strcmp(data[i].status, "SPECIAL CONCERN") == 0)
                {
                    province[j].concern += data[i].count;
                }
                province[j].total += data[i].count;
            }
        }
    }
}

void viewByProvinceDes(struct Provinces province[], int max)
{
    int sumExt = 0, sumExtrd = 0, sumEnd = 0, sumThr = 0, sumConc = 0, sumTotal = 0;
    int sortedIndexes[14] = {0};
    int temp = 0;
    int i, j;

    printf("PROVINCE             EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
    printf("-------------------- ------- ---------- ---------- ---------- ------- ---------\n");

    for (int i = 0; i < max; i++)
    {
        sortedIndexes[i] = province[i].total;
    }

    for (i = 0; i < max; ++i)
    {
        for (j = 0; j < max - 1 - i; ++j)
        {
            if (sortedIndexes[j] < sortedIndexes[j + 1])
            {
                temp = sortedIndexes[j + 1];
                sortedIndexes[j + 1] = sortedIndexes[j];
                sortedIndexes[j] = temp;
            }
        }
    }

    j = 0;
    for (int i = 0; i < max; i++)
    {
        while (j != max)
        {
            if (province[i].total == sortedIndexes[j])
            {
                printf("%-20s    %04d       %04d       %04d       %04d    %04d     %05d\n", province[i].province, province[i].extinct, province[i].extirpated, province[i].endangered, province[i].threatened, province[i].concern, province[i].total);
                j++;
                i = -1;
            }
            i++;
        }

        sumExt += province[i].extinct;
        sumExtrd += province[i].extirpated;
        sumEnd += province[i].endangered;
        sumThr += province[i].threatened;
        sumConc += province[i].concern;
        sumTotal += province[i].total;
    }

    printf("-------------------- ------- ---------- ---------- ---------- ------- ---------\n");
    printf("                       %05d      %05d      %05d      %05d   %05d    %06d\n\n", sumExt, sumExtrd, sumEnd, sumThr, sumConc, sumTotal);
}

// VIEW BY YEAR
void viewByYear(struct FileData data[], int max)
{
    struct Year years[YEARS_AMOUNT] = {{2010}, {2011}, {2012}, {2013}, {2014}, {2015}, {2016}, {2017}, {2018}, {2019}};

    int sumExt = 0, sumExtrd = 0, sumEnd = 0, sumThr = 0, sumConc = 0, sumTotal = 0;

    yearsCounter(data, years, max);

    printf("YEAR EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
    printf("---- ------- ---------- ---------- ---------- ------- ---------\n");
    for (int i = 0; i < YEARS_AMOUNT; i++)
    {
        printf("%04d    %04d       %04d       %04d       %04d    %04d     %05d\n", years[i].year, years[i].extinct, years[i].extirpated, years[i].endangered, years[i].threatened, years[i].concern, years[i].total);
        sumExt += years[i].extinct;
        sumExtrd += years[i].extirpated;
        sumEnd += years[i].endangered;
        sumThr += years[i].threatened;
        sumConc += years[i].concern;
        sumTotal += years[i].total;
    }

    printf("     ------- ---------- ---------- ---------- ------- ---------\n");
    printf("       %04d      %04d      %04d      %04d   %04d    %05d\n\n", sumExt, sumExtrd, sumEnd, sumThr, sumConc, sumTotal);
}

void mainLogic(struct FileData data[], int max)
{
    int selection;

    struct Provinces province[PROVINCE_AMOUNT] = {{"Alberta", "AB"}, {"British Columbia", "BC"}, {"Manitoba", "MB"}, {"New Brunswick", "NB"}, {"Newfoundland", "NL"}, {"Nova Scotia", "NS"}, {"Northwest Territory", "NT"}, {"Nunavut", "NU"}, {"Ontario", "ON"}, {"Prince Edward Island", "PE"}, {"Quebec", "QC"}, {"Saskatchewan", "SK"}, {"Yukon Territory", "YT"}};

    struct Taxon taxon[TAXON_AMOUNT] = {{"Mammals"}, {"Birds"}, {"Reptiles"}, {"Amphibians"}, {"Fishes"}, {"Arthropods"}, {"Molluscs"}, {"Vascular Plants"}, {"Mosses"}, {"Lichens"}};

    initalizationOfProv(data, max, province);
    initializationOfTaxon(data, max, taxon);

    do
    {
        printf("=======================================================\n");
        printf("         Canada Species at Risk Analysis\n");
        printf("            (Data Years: 2010 - 2019)\n");
        printf("=======================================================\n");
        printf("1. View by year (sorted ASCENDING by year)\n");
        printf("2. View by province (sorted DESCENDING by totals)\n");
        printf("3. View by taxon (sorted ASCENDING by totals)\n");
        printf("4. View by province and taxon\n");
        printf("-------------------------------------------------------\n");
        printf("0. Exit\n");
        printf("-------------------------------------------------------\n");
        printf("Selection: ");
        selection = inputIntRange(0, 4);
        printf("\n");
        switch (selection)
        {
        case 0:
            printf("Application Terminated!\n\n");
            break;
        case 1:
            viewByYear(data, max);
            break;
        case 2:
            viewByProvinceDes(province, PROVINCE_AMOUNT);
            break;
        case 3:
            viewByTaxonAsc(taxon, TAXON_AMOUNT);
            break;
        case 4:
            viewByProvAndTax(data, max, province, taxon);
            break;
        }
    } while (selection);

    return;
}

void yearsCounter(struct FileData data[], struct Year years[], int max)
{
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < YEARS_AMOUNT; j++)
        {
            if (data[i].year == years[j].year)
            {
                if (strcmp(data[i].status, "EXTINCT") == 0)
                {
                    years[j].extinct += data[i].count;
                }
                else if (strcmp(data[i].status, "EXTIRPATED") == 0)
                {
                    years[j].extirpated += data[i].count;
                }
                else if (strcmp(data[i].status, "ENDANGERED") == 0)
                {
                    years[j].endangered += data[i].count;
                }
                else if (strcmp(data[i].status, "THREATENED") == 0)
                {
                    years[j].threatened += data[i].count;
                }
                else if (strcmp(data[i].status, "SPECIAL CONCERN") == 0)
                {
                    years[j].concern += data[i].count;
                }
                years[j].total += data[i].count;
            }
        }
    }
};
