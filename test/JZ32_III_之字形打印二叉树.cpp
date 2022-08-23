#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;        // 创建一个二维vector
        if(!root) {
            return res;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);          // 首先将根结点入队
        bool isOrderLeft = true;

        while(!nodeQueue.empty()) {
            deque<int> levelList;           // 创建了一个双端队列
            int size = nodeQueue.size();    // size代表当前存放树结点的队列大小，即
                                            // 当前树节点的个数
            for (int i=0; i<size; i++) {
                auto node = nodeQueue.front();
                nodeQueue.pop();           // 从队列弹出当前结点
                if (isOrderLeft) {
                    levelList.push_back(node->val);    // 如果是从左至右顺序，就后插入双端队列
                } else {
                    levelList.push_front(node->val);   // 如果是从右至左顺序，就前插入队列中，比如先插入2再插入3得到3 2
                } 
                if (node->left) {
                    nodeQueue.push(node->left);
                }
                if (node->right) {
                    nodeQueue.push(node->right);
                }
            } 
            res.emplace_back(levelList.begin(), levelList.end());
            isOrderLeft = !isOrderLeft; 

        }




        return res;
    }
};