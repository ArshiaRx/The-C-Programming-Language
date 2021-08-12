/* Name: Arshia Rahim
Workshop: 9
Date: 2017/04/04
Section: SJJ
*/
#include <stdio.h>
#define MAX_TITLE_SIZE 21

//Type the struct here
struct Book {
	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};

//Type the function prototypes here
void menu();

void flushkeyboard(void);

int readRecord(FILE *fp, struct Book *b2read);

void displayInventory(const char filename[]);

float calculateCapital(const char filename[]);

int searchInventory(FILE *fp, const int isbn2find);

void addBook(const char filename[], struct Book *b2Add);

void checkPrice(const char filename[], const int isbn2find);


int main()
{
	//struct Book mybook; //an object of struct book
	char filename[] = "144_w9_inventory.txt";
	int option = 0, isbn_t;
	float totalCapital = 0;
	struct Book book;


	printf("Welcome to the Book Store\n");
	printf("=========================\n");


	//Open the file, and check for null pointer
	FILE *fp = NULL;

	//If the file is properly opened, display headers, similar to workshop 8
	fp = fopen("144_w9_inventory.txt", "r");
	if (fp != NULL) {
		do
		{
			menu();

			printf("Select: ");
			scanf("%d", &option);

			switch (option) {

			case 0:
				printf("Goodbye!\n");
				(option = 0);
				break;

			case 1:
				displayInventory(filename);
			break;

			case 2:
				addBook(filename, &book);
			break;

			case 3:
				printf("Please input the ISBN number of the book:\n");
				printf("\n");
				scanf("%d", &isbn_t);
				checkPrice(filename, isbn_t);
			break;

			case 4:
				totalCapital = calculateCapital(filename);
				printf("The total capital is: $%.2f.\n", totalCapital);
				break;

			default:
				printf("Invalid input, try again: \n");
				break;
			}
		} while (option != 0);
	}
	else
	{
		printf("File failed to open\n");
	}
	return 0;
}

void menu()
{
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n");
	printf("\n");
}



void displayInventory(const char filename[])
{
	//Define an object of struct Book
	struct Book book;

	//Open the file, and check for null pointer
	FILE *fp = NULL;

	//If the file is properly opened, display headers, similar to workshop 8
	fp = fopen("144_w9_inventory.txt", "r");
	if (fp != NULL) {
		printf("\n\n");
		printf("Inventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");

		while (readRecord(fp, &book) == 5)
		{
			//display the record
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book._isbn, book._title, book._year, book._price, book._qty);
		}


		//Display the footer
		printf("===================================================\n\n");
		//Close the file
		fclose(fp);
	}
	else {
		printf("Failed to open file\n");
	}
}
void flushKeyboard(void)
{
	while (getchar() != '\n');
}

void addBook(const char filename[], struct Book *b2Add)
{
	FILE *fp = NULL;
	fp = fopen(filename, "a+");
	if (fp != NULL)
	{
		printf("ISBN:");
		scanf("%d", &b2Add->_isbn);
		printf("Title:");
		flushKeyboard();
		scanf("%[^\n]s", b2Add->_title);
		printf("Year:");
		scanf("%d", &b2Add->_year);
		printf("Price:");
		scanf("%f", &b2Add->_price);
		printf("Quantity:");
		scanf("%d", &b2Add->_qty);
		if (searchInventory(fp, b2Add->_isbn) == -1)
		{


			fprintf(fp, "\n%d;%f;%d;%d;%s", b2Add->_isbn, b2Add->_price, b2Add->_year, b2Add->_qty, b2Add->_title);
			printf("The book is successfully added to the inventory.\n");
			printf("\n");
		}
		else
		{
			printf("The book exists in the repository!\n");
			printf("\n");
		}
	}
	fclose(fp);
}

void checkPrice(const char filename[], const int isbn2find)
{
	struct Book book;
	int i = 0;
	float price_check;
	FILE *fp = NULL;
	fp = fopen(filename, "r");
	int count = searchInventory(fp, isbn2find);
	rewind(fp);

	if (count != -1)
	{
		for (i = 0; i < count; i++)
		{
			if (readRecord(fp, &book) == 5);
		}
		if (book._isbn == isbn2find)
		{
			price_check = book._price;
		}
		printf("Book %d costs $%.2f\n", isbn2find, price_check);
		printf("\n");
	}
	else
	{
		printf("Book not found.");
	}
	fclose(fp);
}

int searchInventory(FILE *fp, const int isbn2find)
{
	struct Book book;
	int j = 1;
	int flag = -1;
	while (readRecord(fp, &book) == 5)
	{

		if (book._isbn == isbn2find)
		{
			flag = j;
		}
		else
		{
			j++;
		}
	}

	return flag;
}


float calculateCapital(const char filename[])
{

	FILE *fp = NULL;
	//Define an object of struct Book
	struct Book book;
	//Define and initialize total_capital
	float total_capital = 0;
	//Open the file, and check for null pointer
	fp = fopen("144_w9_inventory.txt", "r");
	if (fp != NULL)
	{


		//If the file is properly opened, use a while loop to call readRecord
		while (readRecord(fp, &book) == 5)
			//Accumulate the multiplication of the price of each item to its quantity
		{
			total_capital += (float)book._price * (float)book._qty;
		}
	}


	//Close the file
	fclose(fp);
	//return the total_capital
	return total_capital;
}

int readRecord(FILE *fp, struct Book *b2read)
{
	//Define a variable int rv = 0
	int rv = 0;
	rv = fscanf(fp, "%d;%f;%d;%d;%19[^\n]", &(b2read->_isbn), &(b2read->_price), &(b2read->_year), &(b2read->_qty), b2read->_title);

	return rv;

}

