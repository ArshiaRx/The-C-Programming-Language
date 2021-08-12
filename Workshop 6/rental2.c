/* Workshop: 6 (At_Home) */

// == Vehicle Rentals ==

#include <stdio.h>

#define distRate1  0.69			// Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49			// Rate per Kilometer above 100km 


// Structure Declaration for Vehicle Rentals
struct Rental
{
	int id;						// ID of the Rental Vehicle
	double baseDay;				// Daily Base Price 
	double earnings;			// Total earnings from this rental
};

/* prototype functions addPositive , taxCalc & subtractPositive*/
double addPositive(double amount, double newAmount);

double taxCalc(double price, double rate);

double subtractPositive(double amount, double newAmount);


/* Implement Function addPositive Here*/
double addPositive(double amount, double newAmount) {

	if (newAmount > 0) 
	
		amount = amount + newAmount;
	
	
	return amount;
}

/* Implement Function taxCalc Here */
double taxCalc(double price, double rate) {

	double taxes;
	taxes = price * rate;

	return taxes;
}

/* Implement Function subtractPositive Here*/

double subtractPositive(double amount, double newAmount) {
	
	double subtractPositive;

	if (newAmount > 0) 
	{
		subtractPositive = amount - newAmount;
	}

	return subtractPositive;
}

/* main program */
int main()
{
	const int noVehicles = 3;			// Number of Vehicles [ Changed to 3]
	int option;							// Variable to store the option selected
	int flag;							// Flag to support vehicle ID find
	int tempID;							// To hold user input for vehicle ID
	int i = 0;							// Variable for "for-loop" counters

										// Initialize the struct Vehicle Rental [ New addition for 3 Rentals]
	struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 },{ 125, 29.95, 0 } };

	double taxRate = 14;				// Tax rate is 14%
	double discount = 5;				// Discount amount for rentals (in CAD)
	
	/*Declare Your Variables Here*/

	int nodays = 0;						// Number of days
	int kmdis = 0;						// Killometer distance
	double basePrice = 0;				// Each day base price
	double charge = 0;					// Charge(Total basePrice + kmdis)
	double kmcost = 0;					// Total killomete Cost
	char discount_s;					// Discount Status
	double taxes = 0;					// Indivisual taxes
	double giftCardmount = 0;			// Gift card amount

	printf("***** Rental Vehicle Management App *****\n\n");

	do
	{
		// Display the option list
		printf("1.) Rental Status\n");
		printf("2.) Apply Charges\n");
		printf("3.) Apply Taxes to All Rentals\n");
		printf("4.) Apply Gift Card\n");
		printf("0.) Log out\n\n");
		printf("Please enter an option to continue: ");

		scanf("%d", &option);

		switch (option) {
		case 0: // Exit the program
			break;

		case 1: // Rental Vehicle Status

			printf("\n-- Rental Vehicle Status --\n\n");
			printf("ID#      Earnings\n");
			printf("-------- ----------\n");

			// Use "%8d %10.2lf" formatting to display ID and Earnings for each rental
			
			for (i = 0; i< noVehicles; i++) {
				if (vRent[i].id != 0) {
					printf("%8d %10.2lf\n", vRent[i].id, vRent[i].earnings);
				}
			}
			/* Copy and Paste from In-Lab Case - 1 */
			printf("\n");

			break;

		case 2: // Calculate Rental Charges

			flag = -1;
			printf("\n-- Rental Charges --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);

			// Finding the correct vehicle index
			for (i = 0; i < noVehicles && flag == -1; i++) {
				if (tempID == vRent[i].id) {
					flag = i;     
				}
			}

			if (flag != -1) { 

				// Capture #days for the rental from user input   
				/* Copy and Paste from In-Lab Case - 2 */

				printf("Enter Rental Period (in Days): ");
				scanf("%d", &nodays);

				// Calculate the base price (baseDay * Days)   
				/* Copy and Paste from In-Lab Case - 2 */

				basePrice = (double)(nodays*vRent[flag].baseDay);

				// Calculate cost for Kilometers driven   
				/* Copy and Paste from In-Lab Case - 2 */
				

				printf("Enter kilometers driven: ");
				scanf("%d", &kmdis);

				if (kmdis < 100) {
					
					kmcost = (double)kmdis * distRate1;
					charge = basePrice + kmcost;
				}
				else {
					
					kmcost = (double)(kmdis - 100) * distRate2 + (100 * distRate1);
					charge = basePrice + kmcost;
				}

				// Add base Price and cost for kilometer driven in to a new variable "charge"    
				/* Copy and Paste from In-Lab Case - 2 */


				/* Call addPositive function with current earnings for the rental and
				charge(calculated above) as arguments and assign the returned
				result back to earnings*/
				/* Copy and Paste from In-Lab Case - 2 */

				vRent[flag].earnings = addPositive(vRent[flag].earnings, charge);

				// Apply Discount with a prompt for Y or N
				// If the user input is skipped without being prompted, have one space infront 
				// of %c in the scanf statement => " %c" instead of "%c"

				printf("Apply Discount: ");
				scanf(" %c", &discount_s);

				if (discount_s == 'Y' || discount_s == 'y') {

					/* If the input is 'Y' or 'y' then call function subtractPositive with current earnings
					for the rental and discount (5 CAD) as arguments and assign the returned
					result back to earnings
					*/
					vRent[flag].earnings = subtractPositive(vRent[flag].earnings, discount);
				}
				else if (discount_s == 'N' || discount_s == 'n') {

				}

				// Display Base Charge, cost for km and the Total 
				printf("\nBase   kmCost DiscStatus Total\n");
				printf("====== ====== ========== ======\n");

				// Use "%6.2lf %6.2lf %10c %6.2lf" formatting inside a printf statement
				printf("%6.2lf %6.2lf %10c %6.2lf\n", basePrice, kmcost, discount_s, vRent[flag].earnings);
				printf("\n");

				break;
			}

			else {
				printf("ERROR: Vehicle ID does not exist.\n\n");
			}
			printf("\n");

			break;

		case 3: // Apply Taxes to all Earnings

			printf("\n-- Apply Taxes To all Accounts--\n\n");


			// Iterate over all Rentals. For each rental, calculate the taxes by calling taxCalc 

			printf("ID#      Earnings   Taxes\n");
			printf("-------- ---------- ------\n");

			
			// by passing current earnings and tax rate
			for (flag = 0; flag < noVehicles; flag++) {
				taxRate = 14;
				taxRate = taxRate*0.01;
				taxes = taxCalc(vRent[flag].earnings, taxRate);

			// Then call addPositive with current earnings and the taxes returned from taxCalc function

			vRent[flag].earnings = addPositive(vRent[flag].earnings, taxes);

			// Then use "%8d %10.2lf %6.2lf" formatting to display ID, Earnings and taxes for each rental

			printf("%8d %10.2lf %6.2lf", vRent[flag].id, vRent[flag].earnings, taxes);
			printf("\n");

			}
			printf("\n");
			break;

		case 4: // Apply Gift Card

			flag = -1;
			printf("\n-- Apply Gift Card --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);


			// Finding the correct vehicle index
			for (i = 0; i < noVehicles && flag == -1; i++) {
				if (tempID == vRent[i].id) {
					flag = i;
				}
			}
			if (flag != -1) {

				// Capture Gift card amount
				printf("Enter Gift Card Amount: ");
				scanf("%lf", &giftCardmount);

				/* call function subtractPositive with current earnings for the rental and Gift card
				amount as arguments and assign the returned result back to earnings
				*/
				vRent[flag].earnings = subtractPositive(vRent[flag].earnings, giftCardmount);
				printf("Discount Applied\n");

			}
			else {
				printf("ERROR: Vehicle ID does not exist.\n");
			}

			printf("\n");

			break;

		default:
			printf("Error: Please enter a valid option to continue\n\n");
			break;
		}


	} while (option != 0);


	return 0;
}

/* SAMPLE INPUT/OUTPUT EXPECTED */

/*

***** Rental Vehicle Management App *****

1.) Rental Status
2.) Apply Charges
3.) Apply Taxes to All Rentals
4.) Apply Gift Card
0.) Log out

Please enter an option to continue: 2

-- Rental Charges --

Enter vehicle ID: 123
Enter Rental Period (in Days): 2
Enter kilometers driven: 125
Apply Discount: Y

Base   kmCost DiscStatus Total
====== ====== ========== ======
19.90  81.25          Y  96.15

1.) Rental Status
2.) Apply Charges
3.) Apply Taxes to All Rentals
4.) Apply Gift Card
0.) Log out

Please enter an option to continue: 2

-- Rental Charges --

Enter vehicle ID: 124
Enter Rental Period (in Days): 3
Enter kilometers driven: 60
Apply Discount: N

Base   kmCost DiscStatus Total
====== ====== ========== ======
59.85  41.40          N 101.25

1.) Rental Status
2.) Apply Charges
3.) Apply Taxes to All Rentals
4.) Apply Gift Card
0.) Log out

Please enter an option to continue: 2

-- Rental Charges --

Enter vehicle ID: 125
Enter Rental Period (in Days): 1
Enter kilometers driven: 223
Apply Discount: Y

Base   kmCost DiscStatus Total
====== ====== ========== ======
29.95 129.27          Y 154.22

1.) Rental Status
2.) Apply Charges
3.) Apply Taxes to All Rentals
4.) Apply Gift Card
0.) Log out

Please enter an option to continue: 1

-- Rental Vehicle Status --

ID#      Earnings
-------- ----------
123      96.15
124     101.25
125     154.22

1.) Rental Status
2.) Apply Charges
3.) Apply Taxes to All Rentals
4.) Apply Gift Card
0.) Log out

Please enter an option to continue: 3

-- Apply Taxes To all Accounts--

ID#      Earnings   Taxes
-------- ---------- ------
123     109.61  13.46
124     115.42  14.18
125     175.81  21.59

1.) Rental Status
2.) Apply Charges
3.) Apply Taxes to All Rentals
4.) Apply Gift Card
0.) Log out

Please enter an option to continue: 4

-- Apply Gift Card --

Enter vehicle ID: 125
Enter Gift Card Amount: 23
Discount Applied

1.) Rental Status
2.) Apply Charges
3.) Apply Taxes to All Rentals
4.) Apply Gift Card
0.) Log out

Please enter an option to continue: 1

-- Rental Vehicle Status --

ID#      Earnings
-------- ----------
123     109.61
124     115.42
125     152.81

1.) Rental Status
2.) Apply Charges
3.) Apply Taxes to All Rentals
4.) Apply Gift Card
0.) Log out

Please enter an option to continue: 0

*/
