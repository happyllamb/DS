#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef int HDataType;

typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;

void shiftDown(int* arr, int n, int cur);
void shiftUp(int* arr, int n, int cur);

//堆的创建
void heapInit(heap* hp)
{
	if (hp == 0)
		return;
	hp->_data = NULL;
	hp->_size = hp->_capacity = 0;
}

//容量检查
void checkCapacity(heap* hp)
{
	if (hp->_size == hp->_capacity)
	{
		int newCapacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType) * newCapacity);
		hp->_capacity = newCapacity;
	}
}

//堆的插入
void heapPush(heap* hp, HDataType val)
{
	if (hp == 0)
		return;
	checkCapacity(hp);
	hp->_data[hp->_size] = val;
	hp->_size++;
	shiftUp(hp->_data, hp->_size, hp->_size - 1);
}

//堆的删除
void heapPop(heap* hp)
{
	if (hp->_size > 0)
	{
		//交换堆顶元素和最后一个元素
		int tem = hp->_data[0];
		hp->_data[0] = hp->_data[hp->_size - 1];
		hp->_data[hp->_size - 1] = tem;

		//尾删
		hp->_size--;
		
		//从堆顶位置开始向下调整
		shiftDown(hp->_data, hp->_size, 0);

	}
}

//获取堆顶元素
HDataType heapTop(heap* hp)
{
	return hp->_data[0];
}


//判断堆是否为空
int heapEmpty(heap* hp)
{
	if (hp == 0 || hp->_size == 0)
		return 1;
	else
		return 0;
}




//假设小堆


//向下调整
void shiftDown(int* arr, int n, int cur)
{
	//找到孩子的位置
	//左孩子
	int child = cur * 2 + 1;
	//右孩子=左孩子+1
	while (child < n)
	{
		//从左右孩子中找一个最小的
		if (child + 1 < n && arr[child + 1] < arr[child])
			child++;
		//和当前数据比较
		//1.调整: 孩子<当前节点的数值
		if (arr[child] < arr[cur])
		{
			//交换数据
			int tem = arr[child];
			arr[child] = arr[cur];
			arr[cur] = tem;

			//更新位置,继续调整
			cur = child;
			child = cur * 2 + 1;
		}
		else
			//2.不调整：孩子>=当前节点的数值
			break;
	}
}

//向上调整算法
void shiftUp(int* arr, int n, int cur)
{
	//找到父节点的位置
	int parent = (cur - 1) / 2;
	while (cur > 0)   //只要不是根节点，继续与父节点进行比较，向上调整
	{
		if (arr[cur] < arr[parent])
		{
			int tem = arr[parent];
			arr[parent] = arr[cur];
			arr[cur] = tem;

			//更新位置
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;
	}
}


//堆排序
void heapSort()
{
	int arr[] = {17,4,16,5,3};
	int n = sizeof(arr) / sizeof(arr[0]);
	//建堆
	for (int i = (i - 2) / 2; i <= 0; i--)
	{
		shiftDown(arr, n, i);
	}
	//堆排序
	int end = n - 1;
	while (end > 0)
	{
		//删除堆顶元素：交换堆顶元素与最后一个元素的位置，向下调整
		int tem = arr[end];
		arr[end] = arr[0];
		arr[0] = tem;
		shiftDown(arr, end, 0);
		end--;
	}
}




void test()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	heap hp;
	heapInit(&hp);
	for (int i = 0; i < n; i++)
	{
		heapPush(&hp, arr[i]);
	}
}

int main()
{
	test();
	return 0;
}