#include <stdio.h>


void Swap(int* arr, int pos1, int pos2)
{
	int tem = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tem;
}
//ֱ�Ӳ�������
void insertSort(int* arr, int n)
{
	//�����һ�������Ѿ�����
	//��Ҫ�����Ԫ��[1 , n )
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;//end : ����Ԫ�ص����һ��λ��
		int data = arr[i];//����˴���Ҫ�����Ԫ��
		while (end >= 0 && arr[end] > data)
		{
			arr[end + 1] = arr[end];//�����������ƶ�
			end--;
		}
		arr[end + 1] = data;
	}
}

//ϣ������
void shellSort(int* arr, int n)
{
	//gap��ͬ�����ݣ�����λ�õļ��
	int gap = n;
	while (gap > 1)
	{
		//���һ�����򣬼��������1����֤����������ͬһ��
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			int end = i - gap;//ͬ���������ݵ����λ��
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


//ѡ������
void selectSort1(int* arr, int n)
{
	//��δ������������ҵ���ֵ����ŵ�δ�������ʼλ��
	//δ���������[start,end]
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		int min = start;
		//�ҵ���Сֵ��λ��
		for (int i = start + 1; i <= end ; i++)
		{
			if (arr[i] < arr[min])
				min = i;
		}
		//��Сֵ���ڿ�ʼ��λ��
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
	//��δ������������ҵ����ֵ����Сֵ
	//���ֵ�ŵ�ĩβ����Сֵ�ŵ�ͷ��
	//�����Ĵ�������һ��
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
		//��Сֵ���ڿ�ʼ��λ��
		int tem = arr[min];
		arr[min] = arr[start];
		arr[start] = tem;
		//���ֵ����ĩβ��λ��
		if (max == start)
			max = min;
		int tem2= arr[max];
		arr[max] = arr[end];
		arr[end] = tem2;
		start++;
		--end;
	}
}


//������
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