///
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

int main(int argc, char **argv)
{
	int num;
	int neg;
	int pos;
	int coin;
	int *arr;
	int i = 0;
	int j = 0;

	num = atoi(argv[1]);
	arr = (int*)malloc(sizeof(int) * num);
	srand(time(NULL));
	//neg =  INT_MIN + rand();
	pos = rand();
	coin = 0 + rand() % 2;
	while (i < num)
	{
		neg = -100000 + rand() % 100000;
		pos = rand();
		coin = 0 + rand() % 2;
		//if (coin)
		//	printf("%d ", pos);
		//else
		//	printf("%d ", neg);
		j = 0;
		while (j < i)
		{
			if (arr[j] == neg)
				break;
			j++;
		}
		if (arr[j] == neg)
			continue;
		arr[i] = neg;
		i++;
		
	}
	i = 0;
	printf("ARG=\"");
	while (i < num)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\"; ./push_swap $ARG | ./checker $ARG");
	printf("\n");
	return (0);
}