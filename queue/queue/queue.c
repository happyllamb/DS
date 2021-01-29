#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int QDataType;

//����ڵ�
typedef struct QNode
{
	struct QNode* _next;
	QDataType _data;
}QNode;

//�������
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;


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


void test()
{
	Queue q;
	queueInit(&q);
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	queuePop(&q);
	queuePop(&q);
	queuePop(&q);

}

int main()
{
	test();
	return 0;
}