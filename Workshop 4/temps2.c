/*Workshop 4*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int numdays, i, num = 1;
	double averageday;
	double total = 0;
	int high[10];
	int low[10];


	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &numdays);
	printf("\n");

	while (numdays < 3 || numdays > 10)
	{
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &numdays);
		printf("\n");
	}

	for (i = 0; i < numdays; i++)
	{
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
	}

	printf("\n");
	printf("Day  Hi  Low\n");

	for (i = 0; i < numdays; i++)
	{
		printf("%d    %d    %d\n", i + 1, high[i], low[i]);

	}
	printf("\n");

	while (num > 0)
	{
		printf("Enter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &num);
		printf("\n");

		
		while (num > 4)
		{
			printf("Invalid entry, please enter a number between 1 and 4, inclusive: ");
			scanf("%d", &num);
			printf("\n");
		}
		if (num < 0)
		{
			printf("Goodbye!\n");
			return(0);
		}

		for (i = 0; i < num; i++)
		{
			total = total + high[i] + low[i];
		}

		averageday = total / (num * 2);
		printf("The average temperature up to day %d is: %.2lf", num, averageday);
		total = 0;
		printf("\n\n");
		}
	
	return 0;
}
