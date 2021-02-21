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
		//创建以当前数据为根的子树
		BTreeNode* root = (BTreeNode*)malloc(sizeof(BTreeNode));
		root->_data = arr[*idx];
		(*idx)++;

		root->_leftChild = _creatNode(arr, idx);
		root->_rightChild = _creatNode(arr, idx);
		return root;
	}
}


//前序遍历
void preOrder(BTreeNode* root)
{
	if (root)//如果根不为空，就继续遍历
	{
		printf("%c ", root->_data);
		preOrder(root->_leftChild);
		preOrder(root->_rightChild); 
	}
}


//中序遍历
void inOrder(BTreeNode* root)
{
	if (root)
	{
		inOrder(root->_leftChild);
		printf("%c ", root->_data);
		inOrder(root->_rightChild);
	}
}


//后续遍历
void postOrder(BTreeNode* root)
{
	if (root)
	{
		postOrder(root->_leftChild);
		postOrder(root->_rightChild);
		printf("%c ", root->_data);
	}
}


//树的节点的个数
int BTreeSize(BTreeNode* root)
{
	if (root == NULL)
		return 0;
	//总节点个数 = 左子树节点个数 + 右子树节点个数
	return BTreeSize(root->_leftChild) + BTreeSize(root->_rightChild) + 1;
}



//树叶子节点的个数
int BTreeLeafSize(BTreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_leftChild == NULL && root->_rightChild == NULL)
		return 1;
	//总叶子节点个数 = 左子树叶子节点个数 + 右子树叶子结点个数
	return BTreeLeafSize(root->_leftChild) + BTreeLeafSize(root->_rightChild);
}


//树的第k层的节点个数
int BTreeKSize(BTreeNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	//第k层节点 = 左右子树第k-1层节点之和
	return BTreeKSize(root->_leftChild,k-1) + BTreeKSize(root->_rightChild,k-1);
}


//查找树中的元素
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



//树的销毁
void BTreeDestory(BTreeNode** root)
{
	BTreeDestory(&((*root)->_leftChild));
	BTreeDestory(&((*root)->_rightChild));
	free(*root);
	*root = NULL;
}


//树的层序遍历
void BTreeLevelOrder(BTreeNode* root)
{
	Queue q;
	queueInit(&q);
	//根节点存入队列中
	if (root)
		queuePush(&q, root);
	//遍历队列中的每一个节点
	while (!queueEmpty(&q))
	{
		//获取队头元素
		BTreeNode* front = queueFront(&q);
		//出队
		queuePop(&q);
		printf("%c ", front->_data);
		//保存队头元素的左右孩子节点
		if (front->_leftChild)
			queuePush(&q,front->_leftChild);
		if (front->_rightChild)
			queuePush(&q,front->_rightChild);
	}
	printf("\n");

}


//判断树是否为完全二叉树
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
		//获取队头元素
		BTreeNode* front = queueFront(&q);
		//出队
		queuePop(&q);
		//左右孩子入队
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
				//如果剩余元素中有非空节点，说明节点不连续，不是完全二叉树
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
