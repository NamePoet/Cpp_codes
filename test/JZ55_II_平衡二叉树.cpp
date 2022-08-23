
#include <float.h>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// 平衡二叉树：任意节点的左右子树的深度相差不超过1
// 后序遍历：左右根


// 这是一个重复遍历多次的低效解法

// 自顶向下
class Solution {
public:

    int TreeDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        
        int nLeft = TreeDepth(root->left);
        int nRight = TreeDepth(root->right);

        return (nLeft > nRight) ? (nLeft + 1):(nRight + 1);
    }



    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        int left = TreeDepth(root->left);
        int right = TreeDepth(root->right);
        int diff = left - right;
        // 平衡二叉树：任意节点的左右子树的深度相差不超过1
        if (diff > 1 || diff < -1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right); 
    }
};


// 自底向上
class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};