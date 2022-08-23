#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



// DFS深度优先搜索
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;          // 存放路径中元素的向量vector

    void dfs(TreeNode* root, int target)
    {
        if(root == nullptr) {
            return;
        }
        path.emplace_back(root->val);
        target -= root->val;
        // 如果这棵树只有一个根结点，恰好也是对应target的值，直接将该path存入ret这个二维向量中
        if(root->left == nullptr && root->right == nullptr && target == 0)
        {
            // 这里是表示遍历到了叶节点，就可以返回path了
            ret.emplace_back(path);
        }
        dfs(root->left, target);     // 一旦走进一个递归函数，如果没有走到终止条件是不会跳出这个函数的
        dfs(root->right, target);
        path.pop_back();           // 这个步骤很关键，删除栈末尾的哪一个元素
    }




    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return ret;
    }
};