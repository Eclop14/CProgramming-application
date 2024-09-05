#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
int main()
{
	int number[SIZE];
	int most;
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++)
	{
		number[i] = (rand() % 100) + 1;
	}
	for (int i = 0; i < SIZE - 1; i++)
	{
		most = i;
		for (int j = i + 1; j < SIZE; j++)
		{
			if(number[most] < number[j]) most = j;
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		printf("%3d\t", number[i]);
		if ((i + 1) % 10 == 0)printf("\n");
	}
	return 0;
}