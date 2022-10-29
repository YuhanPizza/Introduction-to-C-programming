/*
*****************************************************************************
                          Workshop - #8 (P2)
Full Name  : Lorenz Alvin Tubo
Student ID#: 109934224
Email      : ltubo@myseneca.ca
Section    : IPC144NKK

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include<stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number) {
	int myNumber = 0;
	do {
		scanf("%d", &myNumber);
		if ((myNumber == 0) || (myNumber < 0))
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while ((myNumber == 0) || (myNumber < 0));
	if (number != NULL) {
		*number = myNumber;
	}


	return myNumber;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number) {
	double myDouble = 0;
	do {
		scanf("%lf", &myDouble);
		if ((myDouble == 0.0) || (myDouble < 0.0))
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while ((myDouble == 0.0) || (myDouble < 0.0));
	if (number != NULL) {
		*number = myDouble;
	}

	return myDouble;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(void)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for 3 dry food bags of product data for analysis.\n");
	printf("NOTE: A 'serving' is 64g\n");
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int seqNum)
{
	struct CatFoodInfo c = { 0 };
	printf("\nCat Food Product #%d", seqNum);
	printf("\n--------------------");
	printf("\nSKU           : ");
	scanf("%d", &c.skuNumber);
	do {
		if (c.skuNumber < 0 || c.skuNumber == 0) {
			printf("ERROR: Enter a positive value: ");
			scanf("%d", &c.skuNumber);
		}
	} while (c.skuNumber < 0 || c.skuNumber == 0);
	printf("PRICE         : $");
	scanf("%lf", &c.productPrice);
	do {
		if (c.productPrice < 0 || c.productPrice == 0) {
			printf("ERROR: Enter a positive value: ");
			scanf("%lf", &c.productPrice);
		}
	} while (c.productPrice < 0 || c.productPrice == 0);
	printf("WEIGHT (LBS)  : ");
	scanf("%lf", &c.weightPounds);
	do {
		if (c.weightPounds < 0 || c.weightPounds == 0) {
			printf("ERROR: Enter a positive value: ");
			scanf("%lf", &c.weightPounds);
		}
	} while (c.weightPounds < 0 || c.weightPounds == 0);
	printf("CALORIES/SERV.: ");
	scanf("%d", &c.calories);
	do {
		if (c.calories < 0 || c.calories == 0) {
			printf("ERROR: Enter a positive value: ");
			scanf("%d", &c.calories);
		}
	} while (c.calories < 0 || c.calories == 0);
	return c;

}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int cal)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, cal);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* pound, double* kg)
{	
	double lbs = 0, converted = 0;
	lbs = *pound;
	converted = lbs / ConversionKG;

	if (kg != NULL) {
		*kg = converted;
	}

	return converted;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* B)
{
	double lbsG = 0;
	double lbsKg = *lbs;
	lbsG = convertLbsKg(&lbsKg, NULL);
	lbsG = lbsG * 1000;
	if (B != NULL)
	{
		*B = lbsG;
	}
	return lbsG;
}

// 10. convert lbs: kg and g
void convertLbs(const double* pounds1, double* kg, int* grams)
{
	double pounds = 0, kilo;
	int gram = 0;
	pounds = *pounds1;
	gram =convertLbsG(&pounds, &gram);
	kilo = convertLbsKg(&pounds, &kilo);
	*kg = kilo;
	*grams = gram;
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int* totalGrams, const int* gramsPerServing, double* Servings)
{
	int tGrams = *totalGrams;
	int gramsPS = *gramsPerServing;
	double Serv = ((double)tGrams / (double)gramsPS);
	if (Servings != NULL) {
		*Servings = Serv;
	}
	return Serv;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* serv, double* costPerServ)
{
	double Fprice = *price, Fserv = *serv;
	double servingCost = Fprice / Fserv;
	if (costPerServ != NULL) {
		*costPerServ = servingCost;
	}
	return servingCost;
}
// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* Tcalories, double* costPerCal)
{
	double Fprice = *price, FTcalories = *Tcalories;
	double dollarPerCal = Fprice / FTcalories;
	if (costPerCal != NULL) {
		*costPerCal = dollarPerCal;
	}

	return dollarPerCal;
}


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo *c)
{
	struct ReportData a = { 0 };
	int gram = Grams;
	a.sku = c->skuNumber;
	a.price = c->productPrice;
	a.pounds = c->weightPounds;
	a.serving = c->calories;
	convertLbs(&a.pounds, &a.kilo, &a.grams);
	a.totalServing = calculateServings(&a.grams, &gram, &a.totalServing);
	a.costPerServing = calculateCostPerServing(&a.price, &a.totalServing, &a.costPerServing);
	double totalcalories = a.serving * a.totalServing;
	a.costOfCalPerServ = calculateCostPerCal(&a.price, &totalcalories, &a.costOfCalPerServ);

	return a;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", Grams);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData c, const int a)
{	

	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", c.sku, c.price, c.pounds, c.kilo, c.grams, c.serving, c.totalServing, c.costPerServing, c.costOfCalPerServ);
	if (a > 0) {
		printf(" ***");
	}
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo functionData)
{	
	printf("\nFinal Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n", functionData.skuNumber, functionData.productPrice);
	printf("\nHappy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void) {
	openingMessage();
	struct CatFoodInfo foodInfo[Maximum];
	struct ReportData data[Maximum];
	int i, j = 0;
	for (i = 1; i <= Maximum; i++) {
		foodInfo[i - 1] = getCatFoodInfo(i);
	}
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < Maximum; i++) {
		displayCatFoodData(foodInfo[i].skuNumber, &foodInfo[i].productPrice, &foodInfo[i].weightPounds, foodInfo[i].calories);
	}
	printf("\n");
	for (i = 0; i < Maximum; i++) {
		data[i] = calculateReportData(&foodInfo[i]);
	}
	double cheapest = data[0].costPerServing;
	displayReportHeader();
	for (i = 0; i < Maximum; i++) {
		if (cheapest >= data[i].costPerServing) {
			cheapest = data[i].costPerServing;
		}
	}
	for (i = 0; i < Maximum; i++) {
		j = 0;
		if (cheapest == data[i].costPerServing) {
			j++;
		}
		displayReportData(data[i], j);
		printf("\n");
	}

	for (i = 0; i < Maximum; i++) {

		if (cheapest == data[i].costPerServing) {
			displayFinalAnalysis(foodInfo[i]);
		}
	}

}
