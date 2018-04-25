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

int quickSort(int* a, int begin , int end)
{
	int i = begin;
	int j = end;
	if(begin >= end)
		return 1;
	
	int key = a[begin];
	
	while(begin < end)
	{
		while(a[end] >= key && begin < end)
		{
			end--;
		}
		
		swap(a, begin, end);
		
		while(a[begin] <= key && begin < end)
		{
			begin++;
		}
		
		swap(a, begin, end);
	}
	
	quickSort(a, i, begin - 1);
	quickSort(a, begin + 1, j);
	return 1;
}

int main()
{
   int a[9] = {9,8,7,6,5,4,3,2,1};
   quickSort(a, 0, 8);
   int i;
	
   for(i = 0; i < 9; i++)
   {
   		printf("%d ", a[i]);
   }
   
   return 0;
}