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

#define PROVINCE_LEN 3
#define PROVINCE_AMOUNT 13
#define TAXON_AMOUNT 10
#define YEARS_AMOUNT 10
#define TAXON_LEN 20
#define STATUS_LEN 20

// Data Structs
struct FileData
{
    int year;
    char taxon[TAXON_LEN];
    char status[STATUS_LEN];
    int count;
    char province[PROVINCE_LEN];
};
struct Year
{
    int year;
    int extinct;
    int extirpated;
    int endangered;
    int threatened;
    int concern;
    int total;
};
struct Provinces
{
    char province[25];
    char abbreviation[PROVINCE_LEN];
    int extinct;
    int extirpated;
    int endangered;
    int threatened;
    int concern;
    int total;
};
struct Taxon
{
    char species[17];
    int extinct;
    int extirpated;
    int endangered;
    int threatened;
    int concern;
    int total;
};
void clearInputBuffer(void);

int inputInt(void);

int inputIntPositive(void);

int inputIntRange(int lower, int upper);

int loadData(const char *datafile, struct FileData data[], int max);

void mainLogic(struct FileData data[], int max);

// To do: Species at Risk menu
// initalization of Province struct
void initalizationOfProv(struct FileData data[], int max, struct Provinces province[]);
// initialization of taxon struct
void initializationOfTaxon(struct FileData data[], int max, struct Taxon taxon[]);
// To do: View by year (sorted ASCENDING by year)
void viewByYear(struct FileData data[], int max);
// To do: View by province (sorted DESCENDING by totals)
void viewByProvinceDes(struct Provinces province[], int max);
// To do: View by taxon (sorted ASCENDING by totals)
void viewByTaxonAsc(struct Taxon taxon[], int max);
// To do: View by province and taxon
void viewByProvAndTax(struct FileData data[], int max, struct Provinces province[], struct Taxon taxon[]);
// To do: Choose a Taxon function

// To do: Choose a province function

void yearsCounter(struct FileData data[], struct Year years[], int max);