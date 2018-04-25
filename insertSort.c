#include <stdio.h>

//交换数组中的两个数
int swap(int* a, int i, int j)
{
	
	int tmp;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
	
	//为什么不行
	//a[i] ^= a[j] ^= a[i] ^= a[j]; 	

	return 1;
}

int insertSort(int* a, int len)
{
	int i, j;
	int key;
	for(i = 1; i < len; i++)
	{
		key = a[i];
		for(j = i - 1; j >=0; j--)
		{
			if(a[j] > key)
			{
				a[j + 1] = a[j];
			}
			else
				break;
		}
		a[j + 1] = key;
	}
	return 1;
}

int main()
{
   int a[9] = {9,8,7,6,5,4,3,2,1};
   insertSort(a, 9);
   int i;
	
   for(i = 0; i < 9; i++)
   {
   		printf("%d ", a[i]);
   }
   
   return 0;
}