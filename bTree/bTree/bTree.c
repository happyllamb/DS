#include <stdio.h>
#include <stdlib.h>



typedef char BDatatype;
 
typedef struct BTreeNode
{
	BDatatype _data;
	struct BTreeNode* _leftChild;
	struct BTreeNode* _rightChild;
}BTreeNode;


// A B D # # E # H # # C F # # G # #

BTreeNode* creatNode(BDatatype arr[], int* idx)
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

		root->_leftChild = creatNode(arr, idx);
		root->_rightChild = creatNode(arr, idx);
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


//查找树种的元素
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
	test();
	return 0;
}
