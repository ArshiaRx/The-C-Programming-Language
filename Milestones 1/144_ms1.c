/*Milestones: 1
Prof: Ian Tipson*/

#include <stdio.h>
// tools
void welcome(void);
void printTitle(void);
void printFooter(double grandTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);


// code your functions here:

void welcome(void) {
	printf("---=== Grocery Inventory System ===---\n\n");
}

void printTitle(void) {
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

void printFooter(double grandTotal) {
	printf("--------------------------------------------------------+----------------\n");

	if (grandTotal > 0) {
		printf("\t\t\t\t\t   Grand Total: |%12.2lf\n", grandTotal);
	}
}

void flushKeyboard(void) {
	while (getchar() != '\n');
}

void pause(void) {
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}

int getInt(void) {
	char nL = 'x';
	int value;

	while (nL != '\n') {
		scanf("%d%c", &value, &nL); //&nL only receives the declared nL= x even though I type something character
		if (nL != '\n') {
			while (nL != '\n') {
				flushKeyboard();
				printf("Invalid integer, please try again: ");
				scanf("%d%c", &value, &nL);
			}
		}
	}
	return value;
}

int getIntLimited(int lowerLimit, int upperLimit) {

	int valueLimit;
	valueLimit = getInt();
	
	while (valueLimit < lowerLimit || valueLimit > upperLimit) {
		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		valueLimit = getInt();
	}
	return valueLimit;
}

double getDouble(void) {
	char nL = 'x';
	double value;

	while (nL != '\n') {
		scanf("%lf%c", &value, &nL);
		if (nL != '\n') {
			while (nL != '\n') {
				flushKeyboard();
				printf("Invalid number, please try again: ");
				scanf("%lf%c", &value, &nL);
			}
		}
	}
	return value;


}

double getDoubleLimited(double lowerLimit, double upperLimit) {

	double valueLimit;
	valueLimit = getDouble();
	while (valueLimit < lowerLimit || valueLimit > upperLimit) {
		printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);
		valueLimit = getDouble();
	}
	return valueLimit;
}




int yes(void) {
	char response;
	int result;

	scanf("%c", &response);

	while (response != 'Y' && response != 'y' && response != 'N' && response != 'n') {
		printf("Only (Y)es or (N)o are acceptable: ");

		flushKeyboard();
		scanf("%c", &response);

	}

	if (response == 'Y' || response == 'y')
		result = 1;

	if (response == 'N' || response == 'n')
		result = 0;

	return result;
}



int menu(void) {
	int number;

	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");

	number = getIntLimited(0, 7);
	return number;

}


void GroceryInventorySystem(void) {

	int option;
	welcome();
	int exit = 0;
	do {
		option = menu();
		switch (option)
		{
		case 1:
			printf("List Items under construction!\n");
			pause();
			break;
		case 2:
			printf("Search Items under construction!\n");
			pause();
			break;
		case 3:
			printf("Checkout Item under construction!\n");
			pause();
			break;
		case 4:
			printf("Stock Item under construction!\n");
			pause();
			break;
		case 5:
			printf("Add/Update Item under construction!\n");
			pause();
			break;
		case 6:
			printf("Delete Item under construction!\n");
			pause();
			break;
		case 7:
			printf("Search by name under construction!\n");
			pause();
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			if (yes() == 1)

			{
				exit = 1;
			}
			break;
		default:
			printf("Invalid value, 0 < value < 7: ");
			flushKeyboard();
			break;
		}
	} while (exit != 1);

}
