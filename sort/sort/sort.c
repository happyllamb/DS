#include <stdio.h>

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
	shellSort(arr, sizeof(arr) / sizeof(arr[0]));
	printSort(arr, sizeof(arr) / sizeof(arr[0]));
}
int main()
{
	test();
	return 0;
}