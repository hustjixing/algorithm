#include <stdio.h>

//交换数组中的两个数
int swap(int* a, int i, int j)
{
	a[i] = a[i] ^ a[j];
	a[j] = a[i] ^ a[j];
	a[i] = a[i] ^ a[j];
	return 1;
}

//从位置location开始调整堆， 前提是location位置有数据更改， 更改之前location位置的堆是大顶堆
int adjustHeap(int* a, int location, int len)
{
	int i;
	//找到locaotin的左子叶
	for(i = 2 * location + 1; i < len; i = 2 * i + 1)
	{
		//找到location中左子叶和右子叶中较大的那一个
		if(i + 1 < len && a[i] < a[i + 1])
		{
			i++;
		}
		//如果较大的一个大于location， 那么需要交换两个值， 然后从i子叶处继续寻找
		if(a[location] < a[i])
		{
			swap(a, location, i);
			location = i;
		}
		//否则， location大于左右子树， 那么就不需要继续找了，已经调完了
		else
			break;
	}
	return 1;
}

//堆排序入口
int heapSort(int* a, int len)
{
	int i;
	//找到堆的叶子的的父亲， 从最右边的父亲开始调整堆， 从右向左， 从下向上
	for(i = len / 2 - 1; i >= 0 ; i--)
	{
		adjustHeap(a, i, len);
	}
	
	//生成大顶堆， 然后交换顶和最右边的叶子， 然后从新调整--len的堆
	for(i = len - 1; i > 0; i--)
	{
		swap(a, i, 0);
		adjustHeap(a, 0, i);
	}
	return 1;
}


int main()
{
   int a[9] = {9,8,7,6,5,4,3,2,1};
   heapSort(a, 9);
   int i;
	
   for(i = 0; i < 9; i++)
   {
   		printf("%d ", a[i]);
   }
   
   return 0;
}