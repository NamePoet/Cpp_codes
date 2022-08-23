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
        // vector�������Կ����ɱ����飬Ҳ����[]��������ǰ���ڵ�λ�õ�ֵ
        if(!preorder.size())
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);       // �������ջ����ǰջ��ֻ�и����
        int inorderIndex = 0;      // ������������Ľ������
        for (int i=1; i<preorder.size(); i++) {    // ��1��ʼ����Ϊǰ������ĸ�����Ѿ���ջ��
            int preorderVal = preorder[i];     // ǰ�������ֵ
            TreeNode* node = stk.top();     // ����ջ�����
            if (node->val != inorder[inorderIndex]) {
                // ������������ӽ��->�����->���ӽ��
                node->left = new TreeNode(preorderVal);
                // ����ʽ�������ָ�������ָ�룬�Ҳ��ǿ���ͬ���͵Ŀռ䣬ͬʱ��ǰ��
                // �����ĵ�ǰ��ֵ��preorderVal���������ӽ��
                stk.push(node->left);    // ���ý����ջ
            }
            else {
                // ��������������Ԫ���뵱ǰջ��Ԫ��һ�£������ӽڵ�ȫ����ջ���
                // �����ǰջ����
                while(!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                    node = stk.top();      //����ջ��Ԫ��
                    stk.pop();          // ջ��Ԫ�س�ջ
                    ++inorderIndex;      // �����������
                }
                node->right = new TreeNode(preorderVal);  // ��ʱǰ�����ʣ�µ�Ԫ�ؾ������ӽ��
                stk.push(node->right);
            }
        }
        return root;   // ������������(��ʱ���е�������ҽ���ѹ�λ���)
    }
};
  