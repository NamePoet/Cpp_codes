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
        root->right = pTemp;           // ���������ҽڵ���ɽ���

        // ��ͨ���ݹ��;�������ϵ������ν��������ӽ��Ľ�����ҷ���
        if(root->left)
            mirrorTree(root->left);
        if(root->right)
            mirrorTree(root->right);

        return root;
    }
};