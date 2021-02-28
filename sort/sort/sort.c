#include <stdio.h>


void Swap(int* arr, int pos1, int pos2)
{
	int tem = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tem;
}
//直接插入排序
void insertSort(int* arr, int n)
{
	//假设第一个数据已经有序
	//需要排序的元素[1 , n )
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;//end : 有序元素的最后一个位置
		int data = arr[i];//保存此次需要排序的元素
		while (end >= 0 && arr[end] > data)
		{
			arr[end + 1] = arr[end];//大的数据向后移动
			end--;
		}
		arr[end + 1] = data;
	}
}

//希尔排序
void shellSort(int* arr, int n)
{
	//gap：同组数据，相邻位置的间隔
	int gap = n;
	while (gap > 1)
	{
		//最后一趟排序，间隔必须是1，保证所有数据在同一组
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			int end = i - gap;//同组有序数据的最后位置
			int data = arr[i];
			while (end >= 0 && data < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}


//选择排序
void selectSort1(int* arr, int n)
{
	//从未排序的序列中找到最值，存放到未排序的起始位置
	//未排序的区间[start,end]
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		int min = start;
		//找到最小值的位置
		for (int i = start + 1; i <= end ; i++)
		{
			if (arr[i] < arr[min])
				min = i;
		}
		//最小值存在开始的位置
		int tem = arr[min];
		arr[min] = arr[start];
		arr[start] = tem;
		start++;
	}
}


void selectSort2(int* arr, int n)
{
	int start = 0;
	int end = n - 1;
	//从未排序的序列中找到最大值和最小值
	//最大值放到末尾，最小值放到头部
	//遍历的次数减少一半
	while (start < end)
	{
		int min = start;
		int max = start;
		
		for (int i = start + 1; i <= end; i++)
		{
			if (arr[i] < arr[min])
				min = i;
			if (arr[i] > arr[max])
				max = i;
		}
		//最小值存在开始的位置
		int tem = arr[min];
		arr[min] = arr[start];
		arr[start] = tem;
		//最大值存在末尾的位置
		if (max == start)
			max = min;
		int tem2= arr[max];
		arr[max] = arr[end];
		arr[end] = tem2;
		start++;
		--end;
	}
}


//堆排序
void shiftDown(int* arr, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
		{
			++child;
		}
		if (arr[child] > arr[parent])
		{
			Swap(arr, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

void heapSort(int* arr, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(arr, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(arr, end, 0);
		shiftDown(arr, end, 0);
		end--;
	}
}

void printSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);

	}
	printf("\n");
}

void test()
{
	int arr[] = { 10,5,8,3,6,9,1,4,2,7 };
	printSort(arr, sizeof(arr) / sizeof(arr[0]));
	heapSort(arr, sizeof(arr) / sizeof(arr[0]));
	printSort(arr, sizeof(arr) / sizeof(arr[0]));
}
int main()
{
	test();
	return 0;
}