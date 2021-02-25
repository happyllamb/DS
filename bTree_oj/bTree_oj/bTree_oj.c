

//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

//只有给定的树是单值二叉树时，才返回 true；否则返回 false。
//输入：[1, 1, 1, 1, 1, null, 1]
//输出：true

//输入：[2, 2, 2, 5, 2]
//输出：false


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool _isUnivalTree(struct TreeNode* root, int val)
{
    if (root)
        return val == root->val && _isUnivalTree(root->left, val) && _isUnivalTree(root->right, val);
    return true;
}


bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
        return  true;
    return _isUnivalTree(root, root->val);

}



//给定一个二叉树，找出其最大深度。

//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。


//示例：
//给定二叉树[3, 9, 20, null, null, 15, 7]，
//返回它的最大深度 3 。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    if (l > r)
        return l + 1;
    else
        return r + 1;
}



//翻转一棵二叉树。
//4
/// \
//2     7
//1   3 6   9
//输出：

//4
/// \
//7     2
/// \ / \
//9   6 3   1
/// 


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    struct TreeNode* tem = root->left;
    root->left = root->right;
    root->right = tem;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}



//给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。

//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

//输入：p = [1, 2, 3], q = [1, 2, 3]
//输出：true


//输入：p = [1, 2], q = [1, null, 2]
//输出：false


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}



//给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
//
//示例 1:
//给定的树 s :
//
//3
/// \
//4   5
/// \
//1   2
//给定的树 t：
//
//4
/// \
//1   2
//返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
//
//示例 2:
//给定的树 s：
//
//3
/// \
//4   5
/// \
//1   2
///
//0
//给定的树 t：
//
//4
/// \
//1   2
//返回 false。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if (s == NULL)
        return false;
    return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);

}




//给定一个二叉树，检查它是否是镜像对称的。
//
//
//
//例如，二叉树 [1, 2, 2, 3, 4, 4, 3] 是对称的。
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//
//
//但是下面这个 [1, 2, 2, null, 3, null, 3] 则不是镜像对称的:
//
//1
/// \
//2   2
//\   \
//3    3


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool _isSmy(struct TreeNode* left, struct TreeNode* right)
{
    if (left == NULL && right == NULL)
        return true;
    if (left == NULL || right == NULL)
        return false;
    return right->val == left->val && _isSmy(left->left, right->right) && _isSmy(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return _isSmy(root->left, root->right);
}



//定一个二叉树，判断它是否是高度平衡的二叉树。
//
//本题中，一棵高度平衡二叉树定义为：
//
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
//
//
//
//示例 1：
//
//
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出：true
//示例 2：
//
//
//输入：root = [1, 2, 2, 3, 3, null, null, 4, 4]
//输出：false
//示例 3：
//
//输入：root = []
//输出：true
//



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getHight(struct TreeNode* root)
{
    if (root)
    {
        int left = getHight(root->left);
        int right = getHight(root->right);
        if (left > right)
            return left + 1;
        else
            return right + 1;
    }
    return 0;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;
    int l = getHight(root->left);
    int r = getHight(root->right);

    return abs(l - r) < 2 && isBalanced(root->left) && isBalanced(root->right);

}



//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。（非递归）


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

typedef struct TreeNode* SLDatatype;
typedef struct stack
{
    SLDatatype* _data;
    int _size;
    int _capacity;
}stack;

//栈初始化
void stackInit(stack* st)
{
    st->_data = NULL;
    st->_capacity = st->_size = 0;
}

//栈的增容
void checkCapacity(stack* st)
{
    if (st->_capacity == st->_size) {
        int newCapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
        st->_data = (SLDatatype*)realloc(st->_data, sizeof(SLDatatype) * newCapacity);
        st->_capacity = newCapacity;
    }
}

//入栈：尾插
void stackPush(stack* st, SLDatatype val)
{
    if (st == NULL)
        return;
    checkCapacity(st);
    st->_data[st->_size++] = val;
}

//出栈：尾删
void stackPop(stack* st)
{
    if (st == 0)
        return;
    if (st->_size > 0)
        st->_size--;
}

//显示栈顶的数据
SLDatatype stackTop(stack* st)
{
    return st->_data[st->_size - 1];
}


//获取栈有效元素的个数
int stackSize(stack* st)
{
    return st->_size;
}

//检查栈是否为空
int  stackEmpty(stack* st)
{
    if (st == NULL || st->_size == 0)
        return 1;
    return 0;

}

//销毁栈
void stackDestry(stack* st)
{
    if (st)
    {
        if (st->_data)
        {
            free(st->_data);
            st->_data = NULL;
        }
    }
}

int getSize(struct TreeNode* root)
{
    if (root)
    {
        return getSize(root->left) + getSize(root->right) + 1;
    }
    return 0;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int sz = getSize(root);
    int* arr = malloc(sizeof(int) * sz);
    int idx = 0;
    stack st;
    stackInit(&st);
    while (root || !stackEmpty(&st))
    {
        //访问最左路径
        while (root)
        {
            arr[idx++] = root->val;
            stackPush(&st, root);
            root = root->left;
        }
        //获栈顶元素
        root = stackTop(&st);
        stackPop(&st);
        root = root->right;
    }
    *returnSize = idx;
    return arr;

}


给定一个二叉树的根节点 root ，返回它的 中序 遍历。（非递归）

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
    typedef struct TreeNode* SLDatatype;
typedef struct stack
{
    SLDatatype* _data;
    int _size;
    int _capacity;
}stack;

//栈初始化
void stackInit(stack* st)
{
    st->_data = NULL;
    st->_capacity = st->_size = 0;
}

//栈的增容
void checkCapacity(stack* st)
{
    if (st->_capacity == st->_size) {
        int newCapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
        st->_data = (SLDatatype*)realloc(st->_data, sizeof(SLDatatype) * newCapacity);
        st->_capacity = newCapacity;
    }
}

//入栈：尾插
void stackPush(stack* st, SLDatatype val)
{
    if (st == NULL)
        return;
    checkCapacity(st);
    st->_data[st->_size++] = val;
}

//出栈：尾删
void stackPop(stack* st)
{
    if (st == 0)
        return;
    if (st->_size > 0)
        st->_size--;
}

//显示栈顶的数据
SLDatatype stackTop(stack* st)
{
    return st->_data[st->_size - 1];
}


//获取栈有效元素的个数
int stackSize(stack* st)
{
    return st->_size;
}

//检查栈是否为空
int  stackEmpty(stack* st)
{
    if (st == NULL || st->_size == 0)
        return 1;
    return 0;

}

//销毁栈
void stackDestry(stack* st)
{
    if (st)
    {
        if (st->_data)
        {
            free(st->_data);
            st->_data = NULL;
        }
    }
}

int getSize(struct TreeNode* root)
{
    if (root)
    {
        return getSize(root->left) + getSize(root->right) + 1;
    }
    return 0;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int sz = getSize(root);
    int* arr = malloc(sizeof(int) * sz);
    int idx = 0;
    stack st;
    stackInit(&st);
    while (root || !stackEmpty(&st))
    {
        while (root)
        {
            stackPush(&st, root);
            root = root->left;
        }
        root = stackTop(&st);
        stackPop(&st);
        arr[idx++] = root->val;
        root = root->right;
    }
    *returnSize = idx;
    return arr;
}



//给定一个二叉树，返回它的 后序 遍历。（非递归）



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

typedef struct TreeNode* SLDatatype;
typedef struct stack
{
    SLDatatype* _data;
    int _size;
    int _capacity;
}stack;

//栈初始化
void stackInit(stack* st)
{
    st->_data = NULL;
    st->_capacity = st->_size = 0;
}

//栈的增容
void checkCapacity(stack* st)
{
    if (st->_capacity == st->_size) {
        int newCapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
        st->_data = (SLDatatype*)realloc(st->_data, sizeof(SLDatatype) * newCapacity);
        st->_capacity = newCapacity;
    }
}

//入栈：尾插
void stackPush(stack* st, SLDatatype val)
{
    if (st == NULL)
        return;
    checkCapacity(st);
    st->_data[st->_size++] = val;
}

//出栈：尾删
void stackPop(stack* st)
{
    if (st == 0)
        return;
    if (st->_size > 0)
        st->_size--;
}

//显示栈顶的数据
SLDatatype stackTop(stack* st)
{
    return st->_data[st->_size - 1];
}


//获取栈有效元素的个数
int stackSize(stack* st)
{
    return st->_size;
}

//检查栈是否为空
int  stackEmpty(stack* st)
{
    if (st == NULL || st->_size == 0)
        return 1;
    return 0;

}

//销毁栈
void stackDestry(stack* st)
{
    if (st)
    {
        if (st->_data)
        {
            free(st->_data);
            st->_data = NULL;
        }
    }
}

int getSize(struct TreeNode* root)
{
    if (root)
    {
        return getSize(root->left) + getSize(root->right) + 1;
    }
    return 0;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int sz = getSize(root);
    int* arr = malloc(sizeof(int) * sz);
    int idx = 0;
    stack st;
    stackInit(&st);
    //prev：上一次访问的节点
    struct TreeNode* prev = NULL;
    while (root || !stackEmpty(&st))
    {
        //遍历最左路径
        while (root)
        {
            stackPush(&st, root);
            root = root->left;
        }
        //top: 栈顶元素
        struct TreeNode* top = stackTop(&st);
        //判断是否可以访问
        // 可以访问： 没有右子树  或者  右子树已经被访问
        //否则不能访问
        if (top->right == NULL || prev == top->right)
        {
            arr[idx++] = top->val;
            stackPop(&st);
            prev = top;
        }
        else//访问右子树
        {
            root = top->right;
        }
    }
    *returnSize = idx;
    return arr;

}