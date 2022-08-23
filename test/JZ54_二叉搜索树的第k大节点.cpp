#include <vector>
// �������������������Ϊ��������
// �����������Ϊ�ݼ�����
// ������������k��ڵ�<-->���������������ĵ�k���ڵ�

// ������� �� �� �� ��         ������������� �� ��

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ������������ݹ鷨

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


// �����������������
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