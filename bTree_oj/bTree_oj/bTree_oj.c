

//���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������

//ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��
//���룺[1, 1, 1, 1, 1, null, 1]
//�����true

//���룺[2, 2, 2, 5, 2]
//�����false


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



//����һ�����������ҳ��������ȡ�

//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����


//ʾ����
//����������[3, 9, 20, null, null, 15, 7]��
//�������������� 3 ��

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

