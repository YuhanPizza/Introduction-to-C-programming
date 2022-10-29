/*
*****************************************************************************
                          Workshop - #8 (P1)
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
 



// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number){
	int myNumber = 0;
	do{
	scanf("%d", &myNumber);
	if((myNumber == 0) || (myNumber < 0))
	{
		printf("ERROR: Enter a positive value: ");
	}
	}while ((myNumber == 0) || (myNumber < 0));
	if(number != NULL){
	*number = myNumber;
	}


	return myNumber;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number){
	double myDouble = 0;
	do{
	scanf("%lf", &myDouble);
	if((myDouble == 0.0)||(myDouble < 0.0))
	{
		printf("ERROR: Enter a positive value: ");
	}
	}while((myDouble == 0.0)||(myDouble < 0.0));
	if(number != NULL){
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
	do{
	if(c.skuNumber< 0 ||c.skuNumber == 0){
		printf("ERROR: Enter a positive value: ");
		scanf("%d", &c.skuNumber);
	}
	}while(c.skuNumber < 0 || c.skuNumber == 0);
	printf("PRICE         : $");
	scanf("%lf", &c.productPrice);
	do{
	if(c.productPrice < 0 || c.productPrice == 0){
		printf("ERROR: Enter a positive value: ");
		scanf("%lf", &c.productPrice);
	}
	}while(c.productPrice<0 || c.productPrice == 0);
	printf("WEIGHT (LBS)  : ");
	scanf("%lf",&c.weightPounds);
	do{
		if(c.weightPounds < 0 || c.weightPounds == 0){
			printf("ERROR: Enter a positive value: ");
			scanf("%lf",&c.weightPounds);
		}
	}while(c.weightPounds < 0 || c.weightPounds == 0);
	printf("CALORIES/SERV.: ");
	scanf("%d",&c.calories);
	do{
		if(c.calories < 0 || c.calories == 0){
			printf("ERROR: Enter a positive value: ");
			scanf("%d",&c.calories);
		}
	}while(c.calories < 0 || c.calories == 0);
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
	printf("%07d %10.2lf %10.1lf %8d\n", sku,*price,*weight, cal);
}

// 7. Logic entry point
void start(void){
	openingMessage();
	struct CatFoodInfo foodInfo[Maximum];
	int i;
	for(i = 1;i<=Maximum ; i++){
	foodInfo[i-1] = getCatFoodInfo(i);
	}
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < Maximum; i++) {
		displayCatFoodData(foodInfo[i].skuNumber, &foodInfo[i].productPrice, &foodInfo[i].weightPounds, foodInfo[i].calories);
	}
	
}
