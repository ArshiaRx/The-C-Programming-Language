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
	int option = 0;
	double totalCapital;

	printf("Welcome to the Book Store\n");
	printf("=========================\n");

		do
		{
			menu();

			printf("Select: ");
			scanf("%d", &option);
			
			switch (option) {

			case 0:
				printf("Goodbye!");
				printf("\n");
				exit();
				break;

			case 1:
				displayInventory(filename);
				break;

			case 2:

				break;

			case 3:

				break;

			case 4:
				
				totalCapital = calculateCapital(filename);
				printf("The total capital is: $%.2f.\n", totalCapital);
				break;


			default:

				printf("Invalid input, try again:\n");
				break;
			}

		} while (option != 0);
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
		printf("\n\nInventory\n===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");

		while (readRecord(fp, &book) == 5)
		{
			//display the record
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book._isbn, book._title, book._year, book._price, book._qty);
		}


		//Display the footer
		printf("===================================================\n");
		printf("\n");
		//Close the file
		fclose(fp);
	}
	else {
		printf("Failed to open file\n");
	}
	//Use a while loop to call readRecord and display the records.
}

void addBook(const char filename[], struct Book *b2Add)
{
	//Not implemented!
}
void checkPrice(const char filename[], const int isbn2find)
{
	//Not implemented!
}

int searchInventory(FILE *fp, const int isbn2find)
{
	//Not implemented!
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
