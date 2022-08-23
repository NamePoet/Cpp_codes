struct TreeNode {
    int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

 
class Solution {
private:
    bool isSymmetric(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == nullptr && root2 == nullptr)
            return true;
        if(root1 == nullptr || root2 == nullptr)
            return false;
        if(root1->val != root2->val)       // 结构对称而值不对称的情况
            return false;
        
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
        
        
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
};