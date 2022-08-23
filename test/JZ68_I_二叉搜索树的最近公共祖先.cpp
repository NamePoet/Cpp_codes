#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// ������������������һ������������, �ҵ�����������ָ���ڵ������������ȡ�     p  q
// p��q������������Ⱦ��ǴӸ��ڵ㵽����·���ϵġ��ֲ�㡹��Ҳ�������һ����ͬ�Ľڵ㡣
// path_p[i] = path_q[i]

// ���α�����
class Solution {
public:
    vector<TreeNode*> getPath(TreeNode* root, TreeNode* target) {
        vector<TreeNode*> path;        // ����һ������ڵ�·����vector
        TreeNode* node = root;
        while (node != target) {
            path.push_back(node);
            if (target->val < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        // target����ҲҪ����path
        path.push_back(node);
        return path;
        
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p = getPath(root, p);
        vector<TreeNode*> path_q = getPath(root, q);
        TreeNode* ancestor;
        for (int i=0; i<path_p.size() && i<path_q.size(); i++) {
            // ��һ������ָ��·��һ��ʼһ������ͬ�Ľ�㣬������һ����ͬ�Ľ��Ϳ����˳�ѭ����
            if (path_p[i] == path_q[i]) {
                ancestor = path_p[i];
            } else {
                break;
            }
        }   
        return ancestor;
    }
};


// һ�α����������ռ�Ч�ʸ���

// ͬ���Ƚϵ�ǰ������������ֵ�Ĵ�С

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

