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
		//�����Ե�ǰ����Ϊ��������
		BTreeNode* root = (BTreeNode*)malloc(sizeof(BTreeNode));
		root->_data = arr[*idx];
		(*idx)++;

		root->_leftChild = creatNode(arr, idx);
		root->_rightChild = creatNode(arr, idx);
		return root;
	}
}


//ǰ�����
void preOrder(BTreeNode* root)
{
	if (root)//�������Ϊ�գ��ͼ�������
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
