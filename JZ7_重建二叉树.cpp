/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*eg:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Input: preorder = [-1], inorder = [-1]
Output: [-1]

*/
#include <stack>

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // vector向量可以看作可变数组，也是用[]来表明当前所在的位置的值
        if(!preorder.size())
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);       // 根结点入栈，当前栈中只有根结点
        int inorderIndex = 0;      // 定义中序遍历的结点索引
        for (int i=1; i<preorder.size(); i++) {    // 从1开始是因为前序遍历的根结点已经入栈了
            int preorderVal = preorder[i];     // 前序遍历的值
            TreeNode* node = stk.top();     // 访问栈顶结点
            if (node->val != inorder[inorderIndex]) {
                // 中序遍历：左子结点->根结点->右子结点
                node->left = new TreeNode(preorderVal);
                // “等式”左边是指向左结点的指针，右侧是开辟同类型的空间，同时将前序
                // 遍历的当前的值（preorderVal）赋给左子结点
                stk.push(node->left);    // 将该结点入栈
            }
            else {
                // 当中序遍历的序号元素与当前栈顶元素一致，即左子节点全部入栈完毕
                // 如果当前栈不空
                while(!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                    node = stk.top();      //访问栈顶元素
                    stk.pop();          // 栈顶元素出栈
                    ++inorderIndex;      // 继续中序遍历
                }
                node->right = new TreeNode(preorderVal);  // 此时前序遍历剩下的元素就是右子结点
                stk.push(node->right);
            }
        }
        return root;   // 返回这个根结点(此时所有的左结点和右结点已归位完毕)
    }
};
  