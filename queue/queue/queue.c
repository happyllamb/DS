#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int QDataType;

//定义节点
typedef struct QNode
{
	struct QNode* _next;
	QDataType _data;
}QNode;

//定义队列
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;


//初始化队列
void queueInit(Queue* q)
{
	 //创建空队列
	q->_front = q->_rear = NULL;
}

//创建节点
QNode* creatNode(QDataType val)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

//入队列：尾插
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

//出队列：头删
void queuePop(Queue* q)
{
	if (q->_front == NULL)
		return;
	QNode* next = q->_front->_next;
	free(q->_front);
	q->_front = next;
	//检查删除后是否为空队列
	if (q->_front == NULL)
		q->_rear = NULL;//如果不将rear指向NULL，rear还会指向已经free的内存，形成野指针
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