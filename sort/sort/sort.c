#include <stdio.h>

//ֱ�Ӳ�������
void insertSort(int* arr, int n)
{
	//�����һ�������Ѿ�����
	//��Ҫ�����Ԫ��[1 , n )
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;//end : ����Ԫ�ص����һ��λ��
		int data = arr[i];//����˴���Ҫ�����Ԫ��
		while (end >= 0 && arr[end] >= data)
		{
			arr[end + 1] = arr[end];//�����������ƶ�
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