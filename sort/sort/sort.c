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
		while (end >= 0 && arr[end] >= data)
		{
			arr[end + 1] = arr[end];//大的数据向后移动
			end--;
		}
		arr[end + 1] = data;
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
	insertSort(arr, sizeof(arr) / sizeof(arr[0]));
	printSort(arr, sizeof(arr) / sizeof(arr[0]));
}
int main()
{
	test();
	return 0;
}