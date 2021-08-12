/*Workshop 2*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)

{
	int Loonies, Quarters, Dimes, Nickels, Pennies;
	double Amount_due;
	float rest, rest_cash, rest_money, left_over;
	const double GSTcalculation = 1.13;
	
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &Amount_due);

	Amount_due += 0.005;

	Amount_due *= GSTcalculation;
	

	printf("GST: %.2lf\n", GSTcalculation);
	printf("Balance owing: $%.2lf\n", Amount_due);

	Loonies = Amount_due / 1;
	rest = Amount_due - 1 * Loonies;

	printf("Loonies required: %d, balance owing $%.2f\n", Loonies, rest);
	
	Quarters = rest / 0.25;
	Amount_due = rest - 0.25 * Quarters;

	printf("Quarters required: %d, balance owing $%.2lf\n", Quarters, Amount_due);

	Dimes = Amount_due / 0.10;
	rest_cash = Amount_due - 0.10 * Dimes;

	printf("Dimes required: %d, balance owing $%.2lf\n", Dimes, rest_cash);

	Nickels = rest_cash / 0.05;
	rest_money = rest_cash - 0.05 * Nickels;

	printf("Nickels required: %d, balance owing $%.2lf\n", Nickels, rest_money);

	Pennies = rest_money / 0.01;
	left_over = rest_money - 0.01 * Pennies;
	
	printf("Pennies required: %d, balance owing $%.2lf\n", Pennies, left_over);

	return 0;
}



