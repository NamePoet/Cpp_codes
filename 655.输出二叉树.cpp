/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉�?
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // �����������
class Solution {
public:
    int callDepth(TreeNode* root) {
        int h = 0;
        if (root->left) {
            h = max(h, callDepth(root->left) + 1);
        }
        if (root->right) {
            h = max(h, callDepth(root->right) + 1);
        }
        return h;
        // �����������
    }

    void dfs(vector<vector<string>>& res, TreeNode* root, int r, int c, const int& height) {
        res[r][c] = to_string(root->val);
        if (root->left) {
            dfs(res, root->left, r+1, c-(1 << (height- r-1)), height);
            // �˴�λ�����ʾ2��height-r-1�η�
        }
        if (root->right) {
            dfs(res, root->right, r+1, c+(1 << (height-r-1)), height);
        }
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int height = callDepth(root);
        int m = height + 1;
        int n = (1 << (height + 1)) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));   // ����յ�Ԫ��Ӧ�ð������ַ���
        dfs(res, root, 0, (n-1)/2, height);   // �����ڷ�λ��
        return res;
    }
};
// @lc code=end



class Solution {
public:
    int callDepth(TreeNode* root) {
        int res = -1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            res++;
            while (len) {
                len--;
                auto t = q.front();
                q.pop();
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
            }
        }
        return res;        // ���صľ����������(�������������������)
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = callDepth(root);
        int m = height + 1;
        int n = (1 << (height + 1)) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, (n-1) / 2});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int r = get<1>(t), c = get<2>(t);
            res[r][c] = to_string(get<0>(t)->val);
            if (get<0>(t)->left) {
                q.push({get<0>(t)->left, r+1, c-(1 << (height - r - 1))});
            }
            if (get<0>(t)->right) {
                q.push({get<0>(t)->right, r+1, c+(1 << (height - r - 1))});
            }

        }
        return res;

    }
};
 