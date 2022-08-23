#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// 二叉搜索树——给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。     p  q
// p和q的最近公共祖先就是从根节点到它们路径上的「分岔点」，也就是最后一个相同的节点。
// path_p[i] = path_q[i]

// 两次遍历法
class Solution {
public:
    vector<TreeNode*> getPath(TreeNode* root, TreeNode* target) {
        vector<TreeNode*> path;        // 创立一个保存节点路径的vector
        TreeNode* node = root;
        while (node != target) {
            path.push_back(node);
            if (target->val < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        // target本身也要加入path
        path.push_back(node);
        return path;
        
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p = getPath(root, p);
        vector<TreeNode*> path_q = getPath(root, q);
        TreeNode* ancestor;
        for (int i=0; i<path_p.size() && i<path_q.size(); i++) {
            // 这一步就是指从路径一开始一定是相同的结点，遇到第一个不同的结点就可以退出循环了
            if (path_p[i] == path_q[i]) {
                ancestor = path_p[i];
            } else {
                break;
            }
        }   
        return ancestor;
    }
};


// 一次遍历法——空间效率更高

// 同步比较当前结点和两个结点的值的大小

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while (true) {
            if (p->val < ancestor->val && q->val < ancestor->val) {
                ancestor = ancestor->left;
            }
            else if (p->val > ancestor->val && q->val > ancestor->val) {
                ancestor = ancestor->right;
            }
            else {
                break;
            }
        }
        return ancestor;
    }
};

