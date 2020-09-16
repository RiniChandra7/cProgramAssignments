#include <stdio.h>
#include <math.h>

void cantorSet(int n)
{
	double endpoints[2 * n + 2];
	int last = 2 * n + 1;	
	int first = 1;
	double power = 0.0;
	int i;

	endpoints[0] = 0;
	endpoints[last] = 1;

	while(power != n)
	{
		endpoints[first] = 1 / pow(3.0, power + 1);
		endpoints[first + 1] = 2 / pow(3.0, power + 1);
		
		//printf("%f\n", pow(3.0, power));
		power++;
		first += 2;
	}

	printf("\nThe endpoints are as follows: \n");
	for(i = 0; i <= last; i++)
	{
		printf("%3f\t", endpoints[i]);
	}
	printf("\n");
}

int main()
{
	int n;
	printf("Enter the number of steps: ");
	scanf("%d", &n);

	cantorSet(n);

	return 0;
}
