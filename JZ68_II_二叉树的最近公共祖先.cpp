#include <unordered_map>   // 无序哈希表

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 普通二叉树遍历最近公共祖先

class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        // 左子树包含p结点，则右子树包含q结点，反之亦然
        // x恰好是p结点或q结点，而且它的左子树或右子树有一个包含了另一个结点的情况
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        }
        return lson || rson || (root->val == p->val || root->val == q->val);
        // 在左子树中   在右子树中    本身就是
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;        
    
    }
};


// 存储父结点
/*
用哈希表存储所有节点的父节点，然后我们就可以利用节点的父节点信息从 p 结点开始不断往上跳，
并记录已经访问过的节点，再从 q 节点开始不断往上跳，如果碰到已经访问过的节点，
那么这个节点就是我们要找的最近公共祖先。
*/

// 哈希表存储
// 往上遍历
class Solution {
public:
        unordered_map<int, TreeNode*> fa;          // father简写，存储父结点
        // <当前结点的值, 父结点>

        // 从根节点开始往下遍历（递归）
        unordered_map<int, bool> vis;              // visited缩写，表示访问过
        void dfs(TreeNode* root) {
            /*
            从根节点开始遍历整棵二叉树，用哈希表记录每个节点的父节点指针。
            */



            if (root->left != nullptr) {
                fa[root->left->val] = root;           // 根结点是它的左节点的父亲
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
            从 p 节点开始不断往它的祖先移动，并用数据结构记录已经访问过的祖先节点。
            同样，我们再从 q 节点开始不断往它的祖先移动，如果有祖先已经被访问过，
            即意味着这是 p 和 q 的深度最深的公共祖先，即 LCA 节点。
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