#include<stdio.h>
#include<string.h>

int future[7][7], present[7][7] = {
			{0, 0, 0, 0, 0, 0, 0},
			{0, 1, 0, 0, 0, 0, 0},
			{0, 0, 1, 1, 0, 0, 0},
			{0, 1, 0, 0, 0, 1, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
		};

int arCompare()
{
	int i, j;

	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			if (present[i][j] != future[i][j]) {
				return 0;
			}
		}
	}

	return 1;
}

void nextGen()
{
	memset(future, 0, sizeof(future));

	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			int liveN = 0;
			for(int x = -1; x <= 1; x++)
			{
				for(int y = -1; y <= 1; y++)
				{
					liveN += present[i+x][j+y];
				}
			}
			liveN = liveN - present[i][j];

			//Underpopulation
			if(liveN < 2)
			{
				future[i][j] = 0;
			}
			//Overpopulation
			else if(liveN > 3)
			{
				future[i][j] = 0;
			}
			else if(present[i][j]==0 && liveN==3)
			{
				future[i][j]==1;
			}
			else
			{
				if(present[i][j]==1)
				{
					if(liveN==2 || liveN==3)
						future[i][j] = 1;
				}
			}
		}
	}

	printf("Future Generation\n");
	for(int i = 0; i <7; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			printf("%d\t", future[i][j]);
		}
		printf("\n");
	}

	for(int i = 0; i <7; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			present[i][j] = future[i][j];
		}
	}

	memset(future, 0, sizeof(future));
}

void main()
{
	int n;
	int count = 0;

	printf("Present Generation\n");
	for(int i = 0; i <7; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			printf("%d\t", present[i][j]);
		}
		printf("\n");
	}

	printf("Enter the number of iterations:\n");
	scanf("%d", &n);

	nextGen();
	n--;
	count++;

	while (n > 0) {
		if (arCompare() == 1) {
			printf("Generations have converged after %d iterations.\n", count);
			break;
		} else if (n == 0) {
			printf("Completed required number of iterations.\n");
			break;
		} else {
			nextGen();
		}
		n--;
		count++;
	}
}
