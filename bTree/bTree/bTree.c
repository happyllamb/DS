#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "bTree.h"





// A B D # # E # H # # C F # # G # #

BTreeNode* _creatNode(BDatatype arr[], int* idx)
{
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;
	}
	else
	{
		//�����Ե�ǰ����Ϊ��������
		BTreeNode* root = (BTreeNode*)malloc(sizeof(BTreeNode));
		root->_data = arr[*idx];
		(*idx)++;

		root->_leftChild = _creatNode(arr, idx);
		root->_rightChild = _creatNode(arr, idx);
		return root;
	}
}


//ǰ�����
void preOrder(BTreeNode* root)
{
	if (root)//�������Ϊ�գ��ͼ�������
	{
		printf("%c ", root->_data);
		preOrder(root->_leftChild);
		preOrder(root->_rightChild); 
	}
}


//�������
void inOrder(BTreeNode* root)
{
	if (root)
	{
		inOrder(root->_leftChild);
		printf("%c ", root->_data);
		inOrder(root->_rightChild);
	}
}


//��������
void postOrder(BTreeNode* root)
{
	if (root)
	{
		postOrder(root->_leftChild);
		postOrder(root->_rightChild);
		printf("%c ", root->_data);
	}
}


//���Ľڵ�ĸ���
int BTreeSize(BTreeNode* root)
{
	if (root == NULL)
		return 0;
	//�ܽڵ���� = �������ڵ���� + �������ڵ����
	return BTreeSize(root->_leftChild) + BTreeSize(root->_rightChild) + 1;
}



//��Ҷ�ӽڵ�ĸ���
int BTreeLeafSize(BTreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_leftChild == NULL && root->_rightChild == NULL)
		return 1;
	//��Ҷ�ӽڵ���� = ������Ҷ�ӽڵ���� + ������Ҷ�ӽ�����
	return BTreeLeafSize(root->_leftChild) + BTreeLeafSize(root->_rightChild);
}


//���ĵ�k��Ľڵ����
int BTreeKSize(BTreeNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	//��k��ڵ� = ����������k-1��ڵ�֮��
	return BTreeKSize(root->_leftChild,k-1) + BTreeKSize(root->_rightChild,k-1);
}


//�������е�Ԫ��
BTreeNode* BTreeFind(BTreeNode* root, BDatatype ch)
{
	if (root == NULL)
		return NULL;
	if (root->_data == ch)
		return root;
	BTreeNode* node;
	node = BTreeFind(root->_leftChild, ch);
	if (node)
		return node;
	return BTreeFind(root->_rightChild, ch);
}



//��������
void BTreeDestory(BTreeNode** root)
{
	BTreeDestory(&((*root)->_leftChild));
	BTreeDestory(&((*root)->_rightChild));
	free(*root);
	*root = NULL;
}


//���Ĳ������
void BTreeLevelOrder(BTreeNode* root)
{
	Queue q;
	queueInit(&q);
	//���ڵ���������
	if (root)
		queuePush(&q, root);
	//���������е�ÿһ���ڵ�
	while (!queueEmpty(&q))
	{
		//��ȡ��ͷԪ��
		BTreeNode* front = queueFront(&q);
		//����
		queuePop(&q);
		printf("%c ", front->_data);
		//�����ͷԪ�ص����Һ��ӽڵ�
		if (front->_leftChild)
			queuePush(&q,front->_leftChild);
		if (front->_rightChild)
			queuePush(&q,front->_rightChild);
	}
	printf("\n");

}


//�ж����Ƿ�Ϊ��ȫ������
int isCompleteBtree(BTreeNode* root)
{
	Queue q;
	queueInit(&q);
	if (root)
	{
		queuePush(&q, root);
	}
	while (!queueEmpty(&q))
	{
		//��ȡ��ͷԪ��
		BTreeNode* front = queueFront(&q);
		//����
		queuePop(&q);
		//���Һ������
		if (front)
		{
			queuePush(&q, front->_leftChild);
			queuePush(&q, front->_rightChild);
		}
		else
			break;
		while (!queueEmpty(&q))
		{
			BTreeNode* front = queueFront(&q);
			queuePop(&q); 
			if (front)
				//���ʣ��Ԫ�����зǿսڵ㣬˵���ڵ㲻������������ȫ������
				return 0;
		}
		return 1;
	}
}



void test2()
{
	char arr[] = "abc##de#g##f###";
	int idx = 0;
	BTreeNode* root = _creatNode(arr, &idx);
	inOrder(root);
}


void test()
{
	char arr[] = "ABD##E#H##CF##G##";
	int idx = 0;
	BTreeNode* root = creatNode(arr, &idx);
	BTreeNode* node;
	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
	printf("\n");
	printf("size = %d \n", BTreeSize(root));
	printf("leafsize = %d \n", BTreeLeafSize(root));
	printf("ksize = %d \n", BTreeKSize(root, 1));
	printf("ksize = %d \n", BTreeKSize(root, 2));
	printf("ksize = %d \n", BTreeKSize(root, 3));
	printf("ksize = %d \n", BTreeKSize(root, 4));
	node = BTreeFind(root, 'G');
	printf("%p --> %c \n", node, *node);
	
}

int main()
{
	test2();
	return 0;
}
