/*
Name: Arshia Rahim
Student number: 112142161
Email: arahim5
Workshop: 8
Section: SJJ
Date: 2017/03/28
*/

#include <stdio.h>
#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 21

//book struct
struct Book {
	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};


void flushKeyboard(void);

void menu();

void displayInventory(const struct Book book[], const int size);

void addBook(struct Book book[], int *size);

void checkPrice(const struct Book book[], const int size);

int searchInventory(const struct Book book[], const int isbn, const int size);

void flushKeyboard(void)
{
	while (getchar() != '\n');
}

void menu() {

	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("0) Exit.\n\n");
}
void displayInventory(const struct Book book[], const int size) {

	int i = 0;

	printf("\n\nInventory\n===================================================\n");
	printf("ISBN      Title               Year Price  Quantity\n");
	printf("---------+-------------------+----+-------+--------\n");

	for (i = 0; i < size; i++) {
		printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[i]._isbn, book[i]._title, book[i]._year, book[i]._price, book[i]._qty);
	}
	printf("===================================================\n");
	printf("\n");
}

int searchInventory(const struct Book book[], const int isbn, const int size) {

	int i = 0;
	int index = -1;

	while (i < size) {
		if (isbn == book[i]._isbn) {
			index = i;
		}i++;
	}
	return index;
}

void addBook(struct Book book[], int *size) {
	int index = 0, qty = 0;
	if (*size == MAX_BOOKS) {
		printf("The inventory is full\n");
	}
	else {

		printf("ISBN:");
		scanf("%d", &book[*size]._isbn);
		flushKeyboard();
		index = searchInventory(book, book[*size]._isbn, *size);
		if (index == -1) {
			printf("Quantity:");
			scanf("%d", &book[*size]._qty);
			flushKeyboard();

			printf("Title:");
			scanf("%[^\n]s", book[*size]._title);
			flushKeyboard();

			printf("Year:");
			scanf("%d", &book[*size]._year);
			flushKeyboard();

			printf("Price:");
			scanf("%f", &book[*size]._price);
			flushKeyboard();

			printf("The book is successfully added to the inventory.\n\n");

			*size += 1;
		}
		else {

			printf("Quantity:");
			scanf("%d", &qty);
			book[index]._qty += qty;
			printf("The book exists in the repository, quantity is updated.\n\n");
		}
	}
}

void checkPrice(const struct Book book[], const int size) {
	int index = 0; int isbn = 0;
	printf("Please input the ISBN number of the book:\n\n");
	scanf("%d", &isbn);

	flushKeyboard();
	index = searchInventory(book, isbn, size);

	if (index == -1)
	{
		printf("Book does not exist in the bookstore! Please try again.\n");
		printf("\n");
	}
	else {
		printf("Book %d costs $%.2f\n", book[index]._isbn, book[index]._price);
		printf("\n");
	}
}

int main(void) {
	int option = 0;
	struct Book book[MAX_BOOKS];
	int size = 0;

	printf("Welcome to the Book Store\n");
	printf("=========================\n");

	do
	{
		menu();

	
		printf("Select: ");
		scanf("%d", &option);

		switch (option) {

		case 0:
			printf("Goodbye!\n");
			option = 0;
			break;

		case 1:
			if (size == 0) {
				printf("The inventory is empty!\n");
				printf("===================================================\n\n");
			}
			else {
				displayInventory(book, size);
			}
			break;
		case 2:

			addBook(book, &size);

			break;


		case 3:

			checkPrice(book, size);

			break;
		default:

			printf("Invalid input, try again:\n");
			break;

		}
	} while (option != 0);
	return 0;
}