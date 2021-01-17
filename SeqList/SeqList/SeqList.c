#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int SLDaTatype;
//动态顺序表
typedef struct seqList
{
	SLDaTatype* _data;
	int _size;
	int _capacity;
}seqList;

//初始化顺序表
void initseqList(seqList* sl)
{
	sl->_data = NULL;
	sl->_size = 0;
	sl->_capacity = 0;
}

//检查容量
void checkCapacity(seqList* sl)
{
	if (sl == 0)
		return;
	if (sl->_capacity == sl->_size)
	{
		//新的容量
		int newCapacity = sl->_capacity == 0 ? 1 : 2 * sl->_capacity;
		//开辟一个更大的空间
		SLDaTatype* tem = (SLDaTatype*)malloc(sizeof(SLDaTatype) * newCapacity);
		//拷贝现有的数据
		memcpy(tem, sl->_data, sizeof(SLDaTatype) * sl->_size);
		//释放原有数据
		free(sl->_data);
		//更新
		sl->_data = tem;
		sl->_capacity = newCapacity;
	}
}

//尾插一个数据
void pushBack(seqList* sl,SLDaTatype val)
{
	if (sl == NULL)
		return;
	checkCapacity(sl);
	sl->_data[sl->_size] = val;
	sl->_size++;
}

//尾删一个数据
void popBack(seqList* sl)
{
	if (sl == NULL)
		return;
	if (sl->_size > 0)
		sl->_size--;
}

//打印顺序表
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