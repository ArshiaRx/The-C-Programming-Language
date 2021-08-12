/* Milestone: 2 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Define statements:

#define LINEAR 1
#define FORM 0
// Constant TAX value:

const double TAX = 0.13;
// Item structure:

struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};
// Function Prototypes Milestone 1:

void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);

//interface

int yes(void);
void GroceryInventorySystem(void);
int menu(void);

// Function Prototypes Milesone 2:

double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int noOfRecs, int sku, int *index);

// Function Implementations Milestone 1:

void welcome(void)
{
	printf("---=== Grocery Inventory System ===---\n\n");
}

void printTitle(void)
{
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

void printFooter(double grandTotal)
{
	printf("--------------------------------------------------------+----------------\n");

	if (grandTotal > 0)
	{
		printf("                                           Grand Total: |%12.2lf\n", grandTotal);
	}
}

void flushKeyboard(void)
{
	while (getchar() != '\n');
}

void pause(void)
{
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}

int getInt(void)
{
	int flag = 0;
	int integer = 0;
	char newLine;

	do {
		scanf("%d%c", &integer, &newLine);

		if (newLine != '\n') {
			printf("Invalid integer, please try again: ");
			flushKeyboard();
		}
		else {
			flag = 1;
		}
	} while (flag != 1);

	return integer;
}

int getIntLimited(int lowerLimit, int upperLimit)
{
	int value;
	value = getInt();
	while (value > upperLimit || value < lowerLimit)
	{
		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		value = getInt();
	}
	return value;
}

double getDouble(void)
{
	int flag = 0;
	double Double = 0;
	char newLine;

	do {
		scanf("%lf%c", &Double, &newLine);

		if (newLine != '\n') {
			printf("Invalid number, please try again: ");
			flushKeyboard();
		}
		else {
			flag = 1;
		}

	} while (flag != 1);

	return Double;
}

double getDoubleLimited(double lowerLimit, double upperLimit)
{
	double value;
	value = getDouble();
	while (value > upperLimit || value < lowerLimit)
	{
		printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);
		value = getDouble();
	}
	return value;
}

int yes(void)
{
	char YN;
	int value;
	scanf("%c", &YN);
	while (YN != 'y' && YN != 'Y'&& YN != 'n' && YN != 'N')
	{

		printf("Only (Y)es or (N)o are acceptable: ");
		flushKeyboard();
		scanf("%c", &YN);
	}
	if (YN == 'Y' || YN == 'y')
	{
		value = 1;
	}
	if (YN == 'n' || YN == 'N')
	{
		value = 0;
	}
	return value;
}

int menu(void)
{
	int integer = 0;

	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");

	integer = getIntLimited(0, 7);
	return integer;
}
void GroceryInventorySystem(void)
{
	int option = 0;
	int close = 0;
	welcome();

	do {
		option = menu();
		switch (option)
		{
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			if (yes() == 1)
			{
				close = 1;
			}
			break;
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

		default:
			printf("Invalid value, 0 < value < 7: ");
			pause();
			break;
		}
	} while (close != 1);
}

// Function Implementations Milestone 2:
double totalAfterTax(struct Item item)
{
	double Total = 0;

	Total = item.price * item.quantity;
	if (item.isTaxed == 1)
	{
		Total += (Total * TAX);
	}
	return Total;
}


int isLowQuantity(struct Item item)
{
	int flag = 0;
	if (item.quantity < item.minQuantity)
	{
		flag = 1;    //error if the above statement is true
	}
	else
	{
		flag = 0;  //zero means false
	}
	return flag;
}

struct Item itemEntry(int sku)
{
	struct Item item;

	item.sku = sku;							//sku
	printf("        SKU: %d\n", sku);
	
	printf("       Name: ");				//name
	scanf("%20[^\n]", item.name);
	flushKeyboard();

	printf("      Price: ");				//price
	item.price = getDouble();

	printf("   Quantity: ");				//quantity
	item.quantity = getInt();

	printf("Minimum Qty: ");				//minimum_quatity
	item.minQuantity = getInt();

	printf("   Is Taxed: ");				//is_tax
	item.isTaxed = yes();
	flushKeyboard();

	return item;
}

void displayItem(struct Item item, int linear)
{
	//prints item out when linear is true
	if (linear == 1)
	{

		printf("|%3d", item.sku);
		printf("|%-20s", item.name);
		printf("|%8.2lf", item.price);

		if (item.isTaxed == 0)  //if its not taxed retrun no
		{
			return("|   No");
		}
		else
		{
			printf("|  Yes");

		}

		printf("| %3d ", item.quantity);

		printf("| %3d ", item.minQuantity);

		printf("|%12.2lf|", totalAfterTax(item));

		if (item.quantity < item.minQuantity)
		{
			printf("***\n");
		}

		else
		{
			printf("\n");
		}
	}
	//prints out item when linear is false.
	if (linear == 0)
	{
		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.minQuantity);
		if (item.isTaxed == 0)
		{
			printf("   Is Taxed: No\n");
		}
		else
		{
			printf("   Is Taxed: Yes\n");
		}
		if (item.quantity < item.minQuantity)
		{
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
	}
}

void listItems(const struct Item item[], int noOfItems)
{
	int i = 0;
	double grandTotal = 0;

	printTitle();
	for (i = 0; i < noOfItems; i++)
	{
		printf("%-4d", i + 1);
		printf("|%3d", item[i].sku);
		printf("|%-20s", item[i].name);
		printf("|%8.2lf", item[i].price);

		if (item[i].isTaxed == 0)
		{

			printf("|   No");

		}
		else
		{

			printf("|  Yes");

		}

		printf("| %3d ", item[i].quantity);

		printf("| %3d ", item[i].minQuantity);

		printf("|%12.2lf|", totalAfterTax(item[i]));

		if (item[i].quantity < item[i].minQuantity)
		{

			printf("***\n");

		}

		else
		{

			printf("\n");

		}

		grandTotal += totalAfterTax(item[i]);
	}
	printFooter(grandTotal);




}

int locateItem(const struct Item item[], int noOfRecs, int sku, int *index)
{
	int flag;


	for (*index = 0; *index < noOfRecs; (*index)++)
	{

		if (item[*index].sku == sku)
		{

			flag = 1;

		}
		else
		{
			flag = 0;
		}

	}

	(*index)--;

	return flag;
}
// Function Implementations Milestone 2:


