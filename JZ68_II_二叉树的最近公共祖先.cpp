#include <unordered_map>   // �����ϣ��

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ��ͨ���������������������

class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        // ����������p��㣬������������q��㣬��֮��Ȼ
        // xǡ����p����q��㣬������������������������һ����������һ���������
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        }
        return lson || rson || (root->val == p->val || root->val == q->val);
        // ����������   ����������    �������
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;        
    
    }
};


// �洢�����
/*
�ù�ϣ��洢���нڵ�ĸ��ڵ㣬Ȼ�����ǾͿ������ýڵ�ĸ��ڵ���Ϣ�� p ��㿪ʼ������������
����¼�Ѿ����ʹ��Ľڵ㣬�ٴ� q �ڵ㿪ʼ��������������������Ѿ����ʹ��Ľڵ㣬
��ô����ڵ��������Ҫ�ҵ�����������ȡ�
*/

// ��ϣ��洢
// ���ϱ���
class Solution {
public:
        unordered_map<int, TreeNode*> fa;          // father��д���洢�����
        // <��ǰ����ֵ, �����>

        // �Ӹ��ڵ㿪ʼ���±������ݹ飩
        unordered_map<int, bool> vis;              // visited��д����ʾ���ʹ�
        void dfs(TreeNode* root) {
            /*
            �Ӹ��ڵ㿪ʼ�������ö��������ù�ϣ���¼ÿ���ڵ�ĸ��ڵ�ָ�롣
            */



            if (root->left != nullptr) {
                fa[root->left->val] = root;           // �������������ڵ�ĸ���
                dfs(root->left);
            }
            if (root->right != nullptr) {
                fa[root->right->val] = root;
                dfs(root->right);
            }
        }    

        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            fa[root->val] = nullptr;
            dfs(root);

            /*
            �� p �ڵ㿪ʼ���������������ƶ����������ݽṹ��¼�Ѿ����ʹ������Ƚڵ㡣
            ͬ���������ٴ� q �ڵ㿪ʼ���������������ƶ�������������Ѿ������ʹ���
            ����ζ������ p �� q ���������Ĺ������ȣ��� LCA �ڵ㡣
            */


            while (p != nullptr) {
                vis[p->val] = true;
                p = fa[p->val];
            }
            while (q != nullptr) {

                if (vis[q->val])  return q;
                q = fa[q->val];
            }
           return nullptr;
    }
};