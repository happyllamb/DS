#pragma once
#include "bTree.h"


typedef BTreeNode* QDataType;

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
void queueInit(Queue* q);


//创建节点
QNode* creatNode(QDataType val);


//入队列：尾插
void queuePush(Queue* q, QDataType val);



//出队列：头删
void queuePop(Queue* q);



//获取队头元素
QDataType queueFront(Queue* q);




//获取队尾元素
QDataType queueBack(Queue* q);



//获取队列有效元素的个数
int queueSize(Queue* q);




//判断队列是否为空队列，如果为空返回非零，如果不为空返回零
int queueEmpty(Queue* q);




//销毁队列
void queueDestry(Queue* q);

