#include <stdio.h>

int swap(int* a, int i, int j)
{
	int tmp;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

int bubbleSort(int* a, int len)
{
	int i, j;
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len - i - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				swap(a, j, j+1);
			}
		}
	}
}

int my_print(int* a, int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[] = {4, 6, 3, 7, 1, 9, 2};
	bubbleSort(a, 7);
	my_print(a, 7);
}