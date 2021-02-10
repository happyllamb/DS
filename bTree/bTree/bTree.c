#include <stdio.h>
#include <stdlib.h>



typedef char BDatatype;
 
typedef struct BTreeNode
{
	BDatatype _data;
	struct BTreeNode* _leftChild;
	struct BTreeNode* _rightChild;
}BTreeNode;