/*
Name: Arshia Rahim
Student number: 112142161
Email: Arahim5@myseneca.ca
Workshop: 3
Section: SJJ
Date: 2017/feb/6
*/

#include <stdio.h>
#define NUMS 4

int main(void)
{
	int i, low, high;
	int totalHigh = 0;
	int totalLow = 0;
	int highest = 0; 
	int lowest = 0;
	int highest_day, lowest_day;
	double average;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++) {
		printf("Enter the high value for day %d: ", i + 1);
		scanf("%d", &high);
		printf("\n");

		if (high > highest)
		{
			highest_day = i + 1;
			highest = high;
		}

		printf("Enter the low value for day %d: ", i + 1);
		scanf("%d", &low);
		printf("\n");

		
		if (low < lowest)
		{
			lowest_day = i + 1;
			lowest = low;
		}

		while (high > 40 || low < -40 || low >= high) {
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &high);
			printf("\n");

			printf("Enter the low value for day %d: ", i + 1);
			scanf("%d", &low);
			printf("\n");                                                                                                                          
		}

		totalLow = totalLow + low;
		totalHigh = totalHigh + high;

	}
	average = (double)(totalHigh + totalLow) / (NUMS * 2);

	printf("The average (mean) temperature was: %.2lf\n", average);

	printf("The highest temperature was %d, on day %d\n", highest, highest_day);

	printf("The lowest temperature was %d, on day %d\n", lowest, lowest_day);


	return 0;
}