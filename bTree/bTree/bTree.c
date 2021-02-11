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
		printf("%c", root->_data);
		preOrder(root->_leftChild);
		preOrder(root->_rightChild); 
	}
}


void test()
{
	char arr[] = "ABD##E#H##CF##G##";
	int idx = 0;
	BTreeNode* root = creatNode(arr, &idx);
}

int main()
{
	test();
	return 0;
}
