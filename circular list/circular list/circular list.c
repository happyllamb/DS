#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//˫���ͷѭ������
typedef int LDataType;
//����ڵ�
typedef struct listNode
{
	LDataType _data;
	struct listNode* _next;
	struct listNode* _prev;
}listNode;

//��������
typedef struct list
{
	listNode* _head;
}list;

//�����ڵ�
listNode* creatNode(LDataType val)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = node->_prev = NULL;
	return node;
}

//��ʼ������
void listInit(list* lst)
{
	if (lst == 0)
		return;
	//������
	lst->_head = creatNode(0);
	lst->_head->_next = lst->_head->_prev = lst->_head;
}

//β��
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

//βɾ
void listPopBack(list* lst)
{
	if (lst == NULL)
		return;
	//������������ɾ��
	if (lst->_head->_next == lst->_head)
		return;
	//�ǿ�����
	listNode* last = lst->_head->_prev;
	listNode* prev = last->_prev;
	free(last);
	lst->_head->_prev = prev;
	prev->_next = lst->_head;
}

//ͷ��
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

//ͷɾ
void listPopFront(list* lst)
{
	//�п�
	if (lst == NULL || lst->_head->_next == lst->_head)
		return;
	listNode* next = lst->_head->_next;
	listNode* nextnext = next->_next;
	free(next);
	lst->_head->_next = nextnext;
	nextnext->_prev = lst->_head;
}


//��ӡ����
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