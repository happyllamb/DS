

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

