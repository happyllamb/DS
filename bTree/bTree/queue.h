#pragma once
#include "bTree.h"


typedef BTreeNode* QDataType;

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
void queueInit(Queue* q);


//�����ڵ�
QNode* creatNode(QDataType val);


//����У�β��
void queuePush(Queue* q, QDataType val);



//�����У�ͷɾ
void queuePop(Queue* q);



//��ȡ��ͷԪ��
QDataType queueFront(Queue* q);




//��ȡ��βԪ��
QDataType queueBack(Queue* q);



//��ȡ������ЧԪ�صĸ���
int queueSize(Queue* q);




//�ж϶����Ƿ�Ϊ�ն��У����Ϊ�շ��ط��㣬�����Ϊ�շ�����
int queueEmpty(Queue* q);




//���ٶ���
void queueDestry(Queue* q);

