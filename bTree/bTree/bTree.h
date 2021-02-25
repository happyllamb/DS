 #pragma once
typedef char BDatatype;

typedef struct BTreeNode
{
	BDatatype _data;
	struct BTreeNode* _leftChild;
	struct BTreeNode* _rightChild;
}BTreeNode;
