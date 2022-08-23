#include <algorithm>
#include <cstdio>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

// ����һ��DFS�����������
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;     // ���Ϊ0
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};



// ��������BFS�����������
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        while (!Q.empty()) {
            int sz = Q.size();         // �˴�Ϊ1���������ӣ�Ԫ��������Ϊ1
            while (sz > 0) {
                TreeNode* node = Q.front();   Q.pop();
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                sz-=1;
            }
            ans += 1;
        }
        return ans;
    }
};