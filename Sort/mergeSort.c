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

int mergeArray(char* a, int first, int mid, int last, char* c)
{
	int i = 0, j = 0, k = 0;
	int len_a = mid - first - 1;
	int len_b = last - mid;
	char* b = a + len_a;
	while(i < len_a && j < len_b)
	{
		if(a[i] < b[j])
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = b[j++];
		}
	}
	
	while(i < len_a)
	{
		c[k++] = a[i++];
	}
	while(j < len_b)
	{
		c[k++] = b[j++];
	}
	return 1;
}

int mergeSort(int* a, int len)
{
	//todo
	return 1;
}

int main()
{
   int a[9] = {9,8,7,6,5,4,3,2,1};
   mergeSort(a, 9);
   int i;
	
   for(i = 0; i < 9; i++)
   {
   		printf("%d ", a[i]);
   }
   
   return 0;
}