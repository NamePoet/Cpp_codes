#include <vector>
// 二叉搜索树的中序遍历为递增序列
// 中序遍历倒序为递减序列
// 二叉搜索树第k大节点<-->此树中序遍历倒序的第k个节点

// 中序遍历 ： 左 根 右         中序遍历倒序：右 根 左

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 中序遍历——递归法

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        DFS(root, k);
        return ans;
    }
    void DFS(TreeNode* node, int& k) {
        if (node == nullptr) return;
        if (node -> right) DFS(node -> right, k);
        if (--k == 0) {
            ans = node -> val;
            return;
        }
        if (node -> left) DFS(node -> left, k);
    }
private:
    int ans;
};


// 中序遍历——迭代法
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> ans;
        stack<TreeNode*>  stk;
        TreeNode* cur = root;
        while (cur != nullptr || !stk.empty()) {
            if (cur != nullptr) {
                stk.push(cur);
                cur = cur -> right;
            } else {
                cur = stk.top();
                stk.pop();
                if (--k == 0) return cur -> val;
                cur = cur -> left;
            }
        }
        return -1;
    }
};