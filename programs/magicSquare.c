#include<stdio.h>
#include<string.h>

void createMagicSquare(int n)
{
	int magicSquare[n][n];

	memset(magicSquare, 0, sizeof(magicSquare));

	int i = n/2;
	int j = n-1;

	printf("Sum of each row or column = %d\n", (n*(n*n + 1)/2));
	for(int val = 1; val <= n*n;)
	{
		//3rd condition
		if(i==-1 && j==n)
		{
			i = 0;
			j = n-2;
		}
		else
		{
			//1st condition
			if(i < 0)
			{
				i = n-1;
			}

			if(j == n)
			{
				j = 0;
			}
		}

		//2nd condition
		if(magicSquare[i][j] == 0)
		{
			magicSquare[i][j] = val++;
		}
		else
		{
			i = i+1;
			j = j-2;
			continue;
		}

		//default condition
		i = i-1;
		j = j+1;
	
	}


	printf("The magic square of size %dX%d is as follows-\n", n, n);
	for(int x = 0; x < n; x++)
	{
		for(int y = 0; y < n; y++)
		{
			printf("%d\t", magicSquare[x][y]);
		}
		printf("\n");
	}
}

void main()
{
	int sqSize = 0;

	printf("Enter size of magic square: ");
	scanf("%d", &sqSize);

	if(sqSize % 2 == 0)
	{
		printf("Magic square not possible!\n");
	}
	else
	{
		printf("Calculating Magic Square...\n");
		createMagicSquare(sqSize);
	}

}
