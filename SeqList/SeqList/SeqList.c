#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int SLDaTatype;
//��̬˳���
typedef struct seqList
{
	SLDaTatype* _data;
	int _size;
	int _capacity;
}seqList;

//��ʼ��˳���
void initseqList(seqList* sl)
{
	sl->_data = NULL;
	sl->_size = 0;
	sl->_capacity = 0;
}

//�������
void checkCapacity(seqList* sl)
{
	if (sl == 0)
		return;
	if (sl->_capacity == sl->_size)
	{
		//�µ�����
		int newCapacity = sl->_capacity == 0 ? 1 : 2 * sl->_capacity;
		//����һ������Ŀռ�
		SLDaTatype* tem = (SLDaTatype*)malloc(sizeof(SLDaTatype) * newCapacity);
		//�������е�����
		memcpy(tem, sl->_data, sizeof(SLDaTatype) * sl->_size);
		//�ͷ�ԭ������
		free(sl->_data);
		//����
		sl->_data = tem;
		sl->_capacity = newCapacity;
	}
}

//β��һ������
void pushBack(seqList* sl,SLDaTatype val)
{
	if (sl == NULL)
		return;
	checkCapacity(sl);
	sl->_data[sl->_size] = val;
	sl->_size++;
}

//βɾһ������
void popBack(seqList* sl)
{
	if (sl == NULL)
		return;
	if (sl->_size > 0)
		sl->_size--;
}

//��ӡ˳���
void printseqList(seqList* sl)
{
	for (int i = 0; i < sl->_size; i++)
	{
		printf("%d ", sl->_data[i]);
	}
	printf("\n");
}

void test()
{
	seqList sl;
	initseqList(&sl);
	pushBack(&sl, 1);
	printseqList(&sl);
	pushBack(&sl, 2);
	printseqList(&sl);
	pushBack(&sl, 3);
	printseqList(&sl);
	pushBack(&sl, 4);
	printseqList(&sl);
	pushBack(&sl, 5);
	printseqList(&sl);
	popBack(&sl);
	printseqList(&sl);
}
int main()
{
	test();
	return 0;
}