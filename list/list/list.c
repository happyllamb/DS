#include<stdio.h>
#include<stdlib.h>

typedef int LDatatype;
typedef struct listNode {
	LDatatype _data;
	struct listNode* _next;//��һ�����ݴ�ŵ�λ��
}listNode;
typedef struct list {
	listNode* _head;//��ŵ�һ���ڵ�ĵ�ַ
}list;

//��ʼ��
void listInit(list* lst)
{
	if (lst == NULL)
		return;
	lst->_head = NULL;//��ʼ��Ϊ�յ�����
}

//��̬�����µĽڵ�
listNode* creatNode(LDatatype val)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

//β��һ������
void listPushBack(list* lst, LDatatype val)
{
	if (lst == NULL)
		return;
	//��һ��������յ������в����һ������
	if (lst->_head == NULL) {
		lst->_head = creatNode(val);
	}
	//�ڶ�������������ǿյģ��������������ҵ����һ�����ݣ��ں�������µ�����
	else
	{
		listNode* tail = lst->_head;
		while (tail->_next != NULL) {
			tail = tail->_next;
		}
		//��������
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