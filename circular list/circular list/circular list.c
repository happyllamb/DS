#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//双向带头循环链表
typedef int LDataType;
//定义节点
typedef struct listNode
{
	LDataType _data;
	struct listNode* _next;
	struct listNode* _prev;
}listNode;

//定义链表
typedef struct list
{
	listNode* _head;
}list;

//创建节点
listNode* creatNode(LDataType val)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = node->_prev = NULL;
	return node;
}

//初始化链表
void listInit(list* lst)
{
	if (lst == 0)
		return;
	//空链表
	lst->_head = creatNode(0);
	lst->_head->_next = lst->_head->_prev = lst->_head;
}

//尾插
void listPushBack(list* lst, LDataType val)
{
	if (lst == 0)
		return;
	listNode* last = lst->_head->_prev;
	listNode* newNode = creatNode(val);
	last->_next = newNode;
	newNode->_prev = last;
	newNode->_next = lst->_head;
	lst->_head->_prev = newNode;
}

//尾删
void listPopBack(list* lst)
{
	if (lst == NULL)
		return;
	//空链表，不进行删除
	if (lst->_head->_next == lst->_head)
		return;
	//非空链表
	listNode* last = lst->_head->_prev;
	listNode* prev = last->_prev;
	free(last);
	lst->_head->_prev = prev;
	prev->_next = lst->_head;
}

//头插
void listPushFront(list* lst,LDataType val)
{
	if (lst == NULL)
		return;
	listNode* newNode = creatNode(val);
	listNode* next = lst->_head->_next;
	
	lst->_head->_next = newNode;
	newNode->_prev = lst->_head;
	newNode->_next = next;
	next->_prev = newNode;

}

//头删
void listPopFront(list* lst)
{
	//判空
	if (lst == NULL || lst->_head->_next == lst->_head)
		return;
	listNode* next = lst->_head->_next;
	listNode* nextnext = next->_next;
	free(next);
	lst->_head->_next = nextnext;
	nextnext->_prev = lst->_head;
}


//打印链表
void listPrint(list* lst)
{
	listNode* cur = lst->_head->_next;
	while (cur != lst->_head) 
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void test()
{
	list lst;
	listInit(&lst);
	listPushFront(&lst,7);
	listPrint(&lst);
	listPushBack(&lst, 1);
	listPrint(&lst);
	listPushBack(&lst, 2);
	listPrint(&lst);
	listPushFront(&lst, 6);
	listPrint(&lst);
	listPushBack(&lst, 3);
	listPrint(&lst);
	listPushBack(&lst, 4);
	listPrint(&lst);
	listPopFront(&lst);
	listPrint(&lst);
}


int main()
{
	test();
	return 0;
}