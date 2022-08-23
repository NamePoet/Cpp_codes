struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        if (root->left == nullptr && root->right == nullptr)
            return root;
        
        TreeNode* pTemp = root->left;
        root->left = root->right;
        root->right = pTemp;           // 根结点的左右节点完成交换

        // 再通过递归的途径，从上到下依次交换存在子结点的结点左右方向
        if(root->left)
            mirrorTree(root->left);
        if(root->right)
            mirrorTree(root->right);

        return root;
    }
};