#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int SLDatatype;
typedef struct stack
{
	SLDatatype* _data;
	int _size;
	int _capacity;
}stack;

//ջ��ʼ��
void stackInit(stack* st)
{
	st->_data = NULL;
	st->_capacity = st->_size = 0;
}

//ջ������
void checkCapacity(stack* st)
{
	if (st->_capacity == st->_size) {
		int newCapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (int*)realloc(st->_data, sizeof(int) * newCapacity);
		st->_capacity = newCapacity;
	}
}

//��ջ��β��
void stackPush(stack* st, SLDatatype val)
{
	if (st == NULL)
		return;
	checkCapacity(st);
	st->_data[st->_size++] = val;
}

//��ջ��βɾ
void stackPop(stack* st)
{
	if (st == 0)
		return;
	if (st->_size > 0)
		st->_size--;
}

//��ʾջ��������
SLDatatype stackTop(stack* st)
{
	return st->_data[st->_size - 1];
}


//��ȡջ��ЧԪ�صĸ���
int stackSize(stack* st)
{
	return st->_size;
}

//���ջ�Ƿ�Ϊ��
void stackEmpty(stack* st)
{
	if (st == NULL || st->_size == 0)
		return 1;
	return 0;

}

//����ջ
void stackDestry(stack* st)
{
	if (st)
	{
		if (st->_data)
		{
			free(st->_data);
			st->_data = NULL;
		}
	}
}


void test()
{
	stack st;
	stackInit(&st);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
}
int main()
{
	test();
	return 0;
}