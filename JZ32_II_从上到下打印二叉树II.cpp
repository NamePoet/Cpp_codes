#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {    // 二维数组，(node, level）
        vector<vector<int>> result;       // 每一层添加的元素也是一个向量vector
        
        if(root == nullptr)
            return result;
        
        queue<TreeNode*> q;
        q.push(root);       // 根结点入队
        while(!q.empty()) {     // 如果队列不空
            int currentLevelSize = q.size();   // 当前层的大小就是当前队列的大小
            result.push_back(vector<int>());
            for (int i = 1; i <= currentLevelSize; i++) {
                auto node = q.front();      q.pop();  // 弹出之前是要记录这个元素的
                result.back().push_back(node->val);   // 往队尾插入该元素的值
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);

            }
        }

        return result;

    }
};