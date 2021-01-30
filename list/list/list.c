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

//尾删一个数据
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
	//删除节点
	free(tail);
	//修改指向
	if (prev == NULL)//删除的是第一个节点
		lst->_head = NULL;
	else
		prev->_next = NULL;
}

//头插一个数据
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

//头删一个数据
void listPopFront(list* lst)
{
	if (lst == NULL||lst->_head == NULL)
		return;
	listNode* node = lst->_head->_next;
	//释放头结点
	free(lst->_head);
	lst->_head = node;
}

//查找数据
listNode* listFind(list* lst, LDatatype val)
{
	if (lst == NULL || lst->_head == NULL)
		return NULL;
	//从第一个节点开始遍历
	listNode* cur = lst->_head;
	while (cur) {
		if (cur->_data == val) {
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

//在cur节点后面插入一个数据
void listInsertAfter(listNode* cur, LDatatype val)
{
	listNode* node = creatNode(val);
	listNode* next = cur->_next;
	cur->_next = node;
	node->_next = next;
}

//删除cur节点后面的一个数据
void listEraseAfter(listNode* cur)
{
	listNode* next = cur->_next;
	if (next == NULL)
		return;
	listNode* nextnext = next->_next;
	free(next);
	cur->_next = nextnext;
}

//销毁链表
void listDestry(list* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	//从第一个节点开始遍历
	listNode* cur = lst->_head;
	while (cur) {
		listNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	lst->_head = NULL;
}

//打印链表
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