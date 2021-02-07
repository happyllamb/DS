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

//�ѵĴ���
void heapInit(heap* hp)
{
	if (hp == 0)
		return;
	hp->_data = NULL;
	hp->_size = hp->_capacity = 0;
}

//�������
void checkCapacity(heap* hp)
{
	if (hp->_size == hp->_capacity)
	{
		int newCapacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType) * newCapacity);
		hp->_capacity = newCapacity;
	}
}

//�ѵĲ���
void heapPush(heap* hp, HDataType val)
{
	if (hp == 0)
		return;
	checkCapacity(hp);
	hp->_data[hp->_size] = val;
	hp->_size++;
	shiftUp(hp->_data, hp->_size, hp->_size - 1);
}

//�ѵ�ɾ��
void heapPop(heap* hp)
{
	if (hp->_size > 0)
	{
		//�����Ѷ�Ԫ�غ����һ��Ԫ��
		int tem = hp->_data[0];
		hp->_data[0] = hp->_data[hp->_size - 1];
		hp->_data[hp->_size - 1] = tem;

		//βɾ
		hp->_size--;
		
		//�ӶѶ�λ�ÿ�ʼ���µ���
		shiftDown(hp->_data, hp->_size, 0);

	}
}

//��ȡ�Ѷ�Ԫ��
HDataType heapTop(heap* hp)
{
	return hp->_data[0];
}


//�ж϶��Ƿ�Ϊ��
int heapEmpty(heap* hp)
{
	if (hp == 0 || hp->_size == 0)
		return 1;
	else
		return 0;
}




//����С��


//���µ���
void shiftDown(int* arr, int n, int cur)
{
	//�ҵ����ӵ�λ��
	//����
	int child = cur * 2 + 1;
	//�Һ���=����+1
	while (child < n)
	{
		//�����Һ�������һ����С��
		if (child + 1 < n && arr[child + 1] < arr[child])
			child++;
		//�͵�ǰ���ݱȽ�
		//1.����: ����<��ǰ�ڵ����ֵ
		if (arr[child] < arr[cur])
		{
			//��������
			int tem = arr[child];
			arr[child] = arr[cur];
			arr[cur] = tem;

			//����λ��,��������
			cur = child;
			child = cur * 2 + 1;
		}
		else
			//2.������������>=��ǰ�ڵ����ֵ
			break;
	}
}

//���ϵ����㷨
void shiftUp(int* arr, int n, int cur)
{
	//�ҵ����ڵ��λ��
	int parent = (cur - 1) / 2;
	while (cur > 0)   //ֻҪ���Ǹ��ڵ㣬�����븸�ڵ���бȽϣ����ϵ���
	{
		if (arr[cur] < arr[parent])
		{
			int tem = arr[parent];
			arr[parent] = arr[cur];
			arr[cur] = tem;

			//����λ��
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;
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