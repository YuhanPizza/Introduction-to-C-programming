/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    int i;
    displayPatientTableHeader();
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);

        }
    }
    printf("\n");
    return;
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max) {
    int num;
    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        num = inputIntRange(0, 2);
        if (num == 1) {
            searchPatientByPatientNumber(patient, max);
        }
        else if (num == 2) {
            searchPatientByPhoneNumber(patient, max);
        }
    } while (num != 0);
    if (num == 0) {
        printf("\n");
    }

}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max) {
    int i;
    int index = -1;
    int exit = 0;
    int next;
    for (i = 0; i < max && exit == 0; i++) {
        if (patient[i].patientNumber == 0) {
            index = i;
            exit = 1;
        }
    }
    if (index == -1) {
        printf("ERROR: Patient listing is FULL!\n");
    }
    else {
        next = nextPatientNumber(patient, max);
        patient[index].patientNumber = next;

        inputPatient(&patient[index]);

        printf("*** New patient record added ***\n");
    }

    printf("\n");
    return;
}


// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max) {
    int num;
    int index;
    printf("Enter the patient number: ");
    num = inputIntPositive();

    index = findPatientIndexByPatientNum(num, patient, max);

    if (index >= 0) {
        printf("\n");
        menuPatientEdit(&patient[index]);
    }
    else {
        printf("ERROR: Patient record not found!\n");
    }
    return;
}


// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max) {
    int num;
    int index;
    char option;
    printf("Enter the patient number: ");
    num = inputIntPositive();

    index = findPatientIndexByPatientNum(num, patient, max);
    printf("\n");
    if (index >= 0) {
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        option = inputCharOption("yn");
        if (option == 'y') {
            *patient[index].name = '\0';
            patient[index].patientNumber = 0;
            *patient[index].phone.description = '\0';
            *patient[index].phone.number = '\0';
            printf("Patient record has been removed!\n\n");
        }
        else{
            printf("Operation aborted.\n\n");
        }
    }
    else if (index == -1) {
        printf("ERROR: Patient record not found!\n\n");
    }
    return;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data) {
    int i;
    int index;
    displayScheduleTableHeader(&data->appointments->date, 1);
    for (i = 0; i < data->maxAppointments; i++)
    {
        if (data->appointments[i].patientNumber != 0)
        {
            index = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);
            displayScheduleData(&data->patients[index], &data->appointments[i], 1);
        }
    }
    printf("\n");
    return;
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data) {
    int year;
    int month;
    int day;
    int i, k;
    int index;
    printf("Year        : ");
    year = inputIntPositive();

    printf("Month (1-12): ");
    month = inputIntRange(1, 12);
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        printf("Day (1-31)  : ");
        day = inputIntRange(1, 31);
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        printf("Day (1-30)  : ");
        day = inputIntRange(1, 30);
    }
    else {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            printf("Day (1-29)  : ");
            day = inputIntRange(1, 29);
        }
        else {
            printf("Day (1-28)  : ");
            day = inputIntRange(1, 28);
        }
    }
    printf("\n");
    int flag = 1;
    for (k = 0; k < data->maxAppointments && flag == 1; k++) {
        if(data->appointments[k].date.year == year && data->appointments[k].date.month == month
            && data->appointments[k].date.day == day) {
            displayScheduleTableHeader(&data->appointments[k].date, 0);
            flag = 0;
        }
    }
    for (i = 0; i < data->maxAppointments; i++){
        if (data->appointments[i].date.year == year && data->appointments[i].date.month == month 
            && data->appointments[i].date.day == day){
            index = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);
            displayScheduleData(&data->patients[index], &data->appointments[i], 0);
        }
    }
    printf("\n");


    return;
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointments, int maxAppointments,
    struct Patient* patients, int maxPatient) {

    int num;
    int year, month, day, hour, min;
    int Aindex;
    int i;
    int flag = 0;
    int done = 0;
    Aindex = availAppoint(appointments, maxAppointments);


    if (Aindex == -1){
        printf("error");
    }
    else{
        printf("Patient Number: ");
        num = inputIntPositive();
        Aindex = findPatientIndexByPatientNum(num, patients, maxPatient);

        do {
            done = 0;
            printf("Year        : ");
            year = inputIntPositive();
            printf("Month (1-12): ");
            month = inputIntRange(1, 12);
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                printf("Day (1-31)  : ");
                day = inputIntRange(1, 31);
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11) {
                printf("Day (1-30)  : ");
                day = inputIntRange(1, 30);
            }
            else {
                if (!year % 4) {
                    printf("Day (1-29)  : ");
                    day = inputIntRange(1, 29);
                }
                else {
                    printf("Day (1-28)  : ");
                    day = inputIntRange(1, 28);
                }
            }



            printf("Hour (0-23)  : ");
            hour = inputIntRange(1, 23);
            printf("Minute (0-59): ");
            min = inputIntRange(0, 59);
            if (hour > MAX_TIME || hour < MIN_TIME || min % INTERVAL != 0 || (hour == MAX_TIME && min > 0)) {
                do {
                    if (hour > MAX_TIME || hour < MIN_TIME || min % INTERVAL != 0 || (hour == MAX_TIME && min > 0)) {

                        printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");
                        printf("Hour (0-23)  : ");
                        hour = inputIntRange(1, 23);
                        printf("Minute (0-59): ");
                        min = inputIntRange(0, 59);
                    }
                } while (hour > MAX_TIME || hour < MIN_TIME || min % INTERVAL != 0 || (hour == MAX_TIME && min > 0));
            }

            for (i = 0; i < maxAppointments; i++) {

                if (appointments[i].date.year == year && appointments[i].date.month == month && appointments[i].date.day == day &&
                    appointments[i].time.hour == hour && appointments[i].time.min == min && appointments[i].patientNumber != 0) {
                    printf("\nERROR: Appointment timeslot is not available!\n\n");
                    done = -1;
                }

            }
            if (done != -1) {
                flag = 1;
                appointments[Aindex].date.year = year;
                appointments[Aindex].date.month = month;
                appointments[Aindex].date.day = day;
                appointments[Aindex].patientNumber = num;
                appointments[Aindex].time.hour = hour;
                appointments[Aindex].time.min = min;

                printf("\n*** Appointment scheduled! ***\n\n");
                sortAppointments(appointments, maxAppointments);
            }
        } while (flag != 1);
    }
    return;
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointments, int maxAppointments,
    struct Patient* patients, int maxPatient) {
    int year, month, day, num, index;
    char option;
    int i;

    printf("Patient Number: ");
    num = inputIntPositive();

    index = findPatientIndexByPatientNum(num, patients, maxPatient);

    if (index >= 0){
        printf("Year        : ");
        year = inputIntPositive();

        printf("Month (1-12): ");
        month = inputIntRange(1, 12);

        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            printf("Day (1-31)  : ");
            day = inputIntRange(1, 31);
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            printf("Day (1-30)  : ");
            day = inputIntRange(1, 30);
        }
        else {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))  {
                printf("Day (1-29)  : ");
                day = inputIntRange(1, 29);
            }
            else {
                printf("Day (1-28)  : ");
                day = inputIntRange(1, 28);
            }
        }
        printf("\n");
        displayPatientData(&patients[index], FMT_FORM);

        printf("Are you sure you want to remove this appointment (y,n): ");
        option = inputCharOption("yn");
        if (option == 'y'){
            for (i = 0; i < maxAppointments; i++){
                if (appointments[i].date.year == year && appointments[i].date.month == month &&
                    appointments[i].date.day == day && appointments[i].patientNumber == num){
                    appointments[i].patientNumber = '\0';


                }
            }

            printf("\nAppointment record has been removed!\n\n");
        }
        else{
            printf("Operation aborted.\n\n");
        }
    }
    else{
        printf("ERROR: Patient record not found!\n\n");
    }

    return;
}

int availAppoint(struct Appointment appointments[], int maxAppoints) {
    int i, index = -1;
    int flag = 0;
    for (i = 0; i < maxAppoints && flag == 0; i++)
    {
        if (appointments[i].patientNumber == 0)
        {
            index = i;
            flag = 1;
        }
    }
    return index;
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int num;
    int index;
    printf("\nSearch by patient number: ");
    num = inputIntPositive();
    printf("\n");
    index = findPatientIndexByPatientNum(num, patient, max);

    if (index >= 0) {
        displayPatientData(&patient[index], FMT_FORM);
    }
    else {
        printf("*** No records found ***\n");
    }
    printf("\n");
    suspend();

}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    int i;
    int comp = 0;
    int index = 0;

    char cstringValue[PHONE_LEN + 1];
    printf("\nSearch by phone number: ");
    inputCString(cstringValue, PHONE_LEN, PHONE_LEN);
    printf("\n");
    displayPatientTableHeader();

    for (i = 0; i < max; i++) {
        comp = strcmp(cstringValue, patient[i].phone.number);
        if (comp == 0) {
            displayPatientData(&patient[i], FMT_TABLE);
            index++;
        }
    }
    if (index == 0) {
        printf("\n*** No records found ***\n");
    }
    printf("\n");
    suspend();
    return;
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max) {
    int i;
    int highiestNumber = -1;
    for (i = 0; i < max; i++) {
        if (highiestNumber < patient[i].patientNumber) {
            highiestNumber = patient[i].patientNumber;
        }
    }

    highiestNumber++;

    return highiestNumber;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i = 0;
    int found = 0;
    do {
        if (patientNumber == patient[i].patientNumber) {
            found = 1;
        }
        else {
            i++;
        }
    } while (i < max && found == 0);
    if (found == 0) {
        i = -1;
    }
    return i;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient) {
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %.5d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
    return;
}


// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone) {
    int selection;

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    selection = inputIntRange(1, 4);
    char cstringValue[PHONE_LEN + 1];

    if (selection == 1) {
        strcpy(phone->description, "CELL");
        printf("\nContact: %s\n", phone->description);
        printf("Number : ");
        inputNumString(cstringValue, PHONE_LEN);
        strcpy(phone->number, cstringValue);
        printf("\n");
    }
    else if (selection == 2) {
        strcpy(phone->description, "HOME");
        printf("\nContact: %s\n", phone->description);
        printf("Number : ");
        inputNumString(cstringValue, PHONE_LEN);
        strcpy(phone->number, cstringValue);
        printf("\n");
    }
    else if (selection == 3) {
        strcpy(phone->description, "WORK");
        printf("\nContact: %s\n", phone->description);
        printf("Number : ");
        inputNumString(cstringValue, PHONE_LEN);
        strcpy(phone->number, cstringValue);
        printf("\n");
    }
    else if (selection == 4) {
        strcpy(phone->description, "TBD");
    }


    return;
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max) {
    FILE* fp = NULL;
    int i = 0;

    fp = fopen(datafile, "r");

    if (fp != NULL){
        while (i < max && fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, 
                patients[i].name, patients[i].phone.description, patients[i].phone.number)){
            i++;
        }
        fclose(fp);
    }

    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max) {
    FILE* fp = NULL;
    int i = 0;

    fp = fopen(datafile, "r");

    if (fp != NULL){
        while (fscanf(fp, "%d,%d,%d,%d,%d,%d\n", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month,
            &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) == 6){
            i++;
        }
        fclose(fp);
    }
    sortAppointments(appoints, i);
    return i;
}
void sortAppointments(struct Appointment appoints[], int max) {
    int index = 0;
    struct Appointment sortedAppoints[50] = { {0} };
    int loop = 0;
    int i;
    do{
        index = getIndexForLowestDateTime(appoints, max);
        sortedAppoints[loop].patientNumber = appoints[index].patientNumber;
        sortedAppoints[loop].date.year = appoints[index].date.year;
        sortedAppoints[loop].date.month = appoints[index].date.month;
        sortedAppoints[loop].date.day = appoints[index].date.day;
        sortedAppoints[loop].time.hour = appoints[index].time.hour;
        sortedAppoints[loop].time.min = appoints[index].time.min;

        appoints[index].patientNumber = 0;
        loop++;
    } while (loop < 50);


    for (i = 0; i < max; i++){
        appoints[i].patientNumber = sortedAppoints[i].patientNumber;
        appoints[i].date.year = sortedAppoints[i].date.year;
        appoints[i].date.month = sortedAppoints[i].date.month;
        appoints[i].date.day = sortedAppoints[i].date.day;
        appoints[i].time.hour = sortedAppoints[i].time.hour;
        appoints[i].time.min = sortedAppoints[i].time.min;
    }
    return;
}
int getIndexForLowestDateTime(struct Appointment appointments[], int maxAppointments) {
    int lowestYear = 9999;
    int lowestMonth = 12;
    int lowestDay = 31;
    int lowestHour = 24;
    int lowestMin = 60;

    int i;
    int index = 0;

    for (i = 0; i < maxAppointments; i++){
        if (appointments[i].date.year < lowestYear && appointments[i].patientNumber != 0){
            lowestYear = appointments[i].date.year;
        }
    }

    for (i = 0; i < maxAppointments; i++){
        if (appointments[i].date.year == lowestYear && appointments[i].date.month < lowestMonth 
            && appointments[i].patientNumber != 0){
            lowestMonth = appointments[i].date.month;
        }
    }

    for (i = 0; i < maxAppointments; i++){
        if (appointments[i].date.year == lowestYear && appointments[i].date.month == lowestMonth 
            && appointments[i].date.day < lowestDay && appointments[i].patientNumber != 0){
            lowestDay = appointments[i].date.day;
        }
    }

    for (i = 0; i < maxAppointments; i++){
        if (appointments[i].date.year == lowestYear && appointments[i].date.month == lowestMonth && appointments[i].date.day == lowestDay 
            && appointments[i].time.hour < lowestHour && appointments[i].patientNumber != 0){
            lowestHour = appointments[i].time.hour;
        }
    }

    for (i = 0; i < maxAppointments; i++){
        if (appointments[i].date.year == lowestYear && appointments[i].date.month == lowestMonth && appointments[i].date.day == lowestDay 
            && appointments[i].time.hour == lowestHour && appointments[i].time.min < lowestMin && appointments[i].patientNumber != 0){
            lowestMin = appointments[i].time.min;
            index = i;
        }
    }

    return index;
}
void inputNumString(char* string, int max)
{
    int length = 0, exit = 1, i = 0;
    char numbers[100];
    do {
        scanf("%[^\n]s", numbers);
        clearInputBuffer();

        length = 0;
        while (numbers[length] != '\0')
        {
            length++;
        }

        //printf("%d", length);
        if (length != max ) {
            printf("Invalid %d-digit number! Number: ", max);
        }
        else {
            exit = 0;
        }
    } while (exit == 1 && length != max);
    while (numbers[i] != '\0')
    {
        string[i] = numbers[i];
        i++;
    }
    string[i] = '\0';
}