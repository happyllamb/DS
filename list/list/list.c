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

//βɾһ������
void listPopBack(list* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* tail = lst->_head;
	listNode* prev = NULL;
	while (tail->_next != NULL) {
		prev = tail;
		tail = tail->_next;
	}
	//ɾ���ڵ�
	free(tail);
	//�޸�ָ��
	if (prev == NULL)//ɾ�����ǵ�һ���ڵ�
		lst->_head = NULL;
	else
		prev->_next = NULL;
}

//ͷ��һ������
void listPushFront(list* lst, LDatatype val)
{
	if (lst == NULL)
		return;
	if (lst->_head == NULL)
		lst->_head = creatNode(val);
	else {
		listNode* node = creatNode(val);
		listNode* next = lst->_head;
		lst->_head = node;
		node->_next = next;
	}
}

//ͷɾһ������
void listPopFront(list* lst)
{
	if (lst == NULL||lst->_head == NULL)
		return;
	listNode* node = lst->_head->_next;
	//�ͷ�ͷ���
	free(lst->_head);
	lst->_head = node;
}

//��������
listNode* listFind(list* lst, LDatatype val)
{
	if (lst == NULL || lst->_head == NULL)
		return NULL;
	//�ӵ�һ���ڵ㿪ʼ����
	listNode* cur = lst->_head;
	while (cur) {
		if (cur->_data == val) {
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

//��cur�ڵ�������һ������
void listInsertAfter(listNode* cur, LDatatype val)
{
	listNode* node = creatNode(val);
	listNode* next = cur->_next;
	cur->_next = node;
	node->_next = next;
}

//ɾ��cur�ڵ�����һ������
void listEraseAfter(listNode* cur)
{
	listNode* next = cur->_next;
	if (next == NULL)
		return;
	listNode* nextnext = next->_next;
	free(next);
	cur->_next = nextnext;
}

//��������
void listDestry(list* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	//�ӵ�һ���ڵ㿪ʼ����
	listNode* cur = lst->_head;
	while (cur) {
		listNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	lst->_head = NULL;
}

//��ӡ����
void listPrint(list* lst)
{
	listNode* cur = lst->_head;
	while (cur) {
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void test()
{
	list* lst;
	listInit(&lst);
	listPushBack(&lst, 1);
	listPrint(&lst);
	listPushBack(&lst, 2);
	listPrint(&lst);
	listPushBack(&lst, 3);
	listPrint(&lst);
	listPushBack(&lst, 4);
	listPrint(&lst);
	listPushBack(&lst, 5);
	listPrint(&lst);
	listPopBack(&lst);
	listPrint(&lst);
}
int main()
{
	test();
	return 0;
}