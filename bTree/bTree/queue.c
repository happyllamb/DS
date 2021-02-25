#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "bTree.h"


//��ʼ������
void queueInit(Queue* q)
{
	 //�����ն���
	q->_front = q->_rear = NULL;
}

//�����ڵ�
QNode* creatNode(QDataType val)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

//����У�β��
void queuePush(Queue* q, QDataType val)
{
	QNode* node = creatNode(val);
	if (q->_front == NULL)
		q->_front = q->_rear = node;
	else {
		q->_rear->_next = node;
		q->_rear = node;
	}
}

//�����У�ͷɾ
void queuePop(Queue* q)
{
	if (q->_front == NULL)
		return;
	QNode* next = q->_front->_next;
	free(q->_front);
	q->_front = next;
	//���ɾ�����Ƿ�Ϊ�ն���
	if (q->_front == NULL)
		q->_rear = NULL;//�������rearָ��NULL��rear����ָ���Ѿ�free���ڴ棬�γ�Ұָ��
}

//��ȡ��ͷԪ��
QDataType queueFront(Queue* q)
{
	return q->_front->_data;
}

//��ȡ��βԪ��
QDataType queueBack(Queue* q)
{
	return q->_rear->_data;
}

//��ȡ������ЧԪ�صĸ���
int queueSize(Queue* q)
{
	int num = 0;
	QNode* cur = q->_front;
	while (cur)
	{
		num++;
		cur = cur->_next;
	}
	return num;
}

//�ж϶����Ƿ�Ϊ�ն��У����Ϊ�շ��ط��㣬�����Ϊ�շ�����
int queueEmpty(Queue* q)
{
	if (q->_front == NULL)
		return 1;
	return 0;
}

//���ٶ���
void queueDestry(Queue* q)
{
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}


//void test()
//{
//	Queue q;
//	queueInit(&q);
//	queuePush(&q, 1);
//	queuePush(&q, 2);
//	queuePush(&q, 3);
//	queuePop(&q);
//	queuePop(&q);
//	queuePop(&q);
//
//}
//
//int main()
//{
//	test();
//	return 0;
//}