#include<stdio.h>
#include<stdlib.h>

typedef int LDatatype;
typedef struct listNode {
	LDatatype _data;
	struct listNode* _next;//下一个数据存放的位置
}listNode;
typedef struct list {
	listNode* _head;//存放第一个节点的地址
}list;

//初始化
void listInit(list* lst)
{
	if (lst == NULL)
		return;
	lst->_head = NULL;//初始化为空的链表
}

//动态开辟新的节点
listNode* creatNode(LDatatype val)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

//尾插一个数据
void listPushBack(list* lst, LDatatype val)
{
	if (lst == NULL)
		return;
	//第一种情况，空的链表中插入第一个数据
	if (lst->_head == NULL) {
		lst->_head = creatNode(val);
	}
	//第二种情况，链表不是空的，遍历整个链表，找到最后一个数据，在后面插入新的数据
	else
	{
		listNode* tail = lst->_head;
		while (tail->_next != NULL) {
			tail = tail->_next;
		}
		//插入数据
		tail->_next = creatNode(val);
	}
}
void test()
{
	list* lst;
	listInit(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);
}
int main()
{
	test();
	return 0;
}