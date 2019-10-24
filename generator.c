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
	int mid;
	int coin;
	int *arr;
	int i = 0;
	int j = 0;
	FILE *f;

	num = atoi(argv[1]);
	arr = (int*)malloc(sizeof(int) * num);
	srand(time(NULL));
	//neg =  INT_MIN + rand();
	pos = rand();
	coin = 0 + rand() % 2;
	while (i < num)
	{
		neg = INT_MIN + rand();
		pos = rand();
		coin = 0 + rand() % 2;
		if (coin)
			mid = pos;
		else
			mid = neg;
		j = 0;
		while (j < i)
		{
			if (arr[j] == mid)
				break;
			j++;
		}
		if (arr[i] == mid)
			continue;
		arr[i] = mid;
		i++;
		
	}
	i = 0;
	//printf("ARG=\"");
	f = fopen("test_num", "w");
	while (i < num)
	{
		fprintf(f, "%d ", arr[i]);
		i++;
	}
	//printf("\"; ./push_swap $ARG | ./checker $ARG");
	fclose(f);
	//printf("\n");
	return (0);
}