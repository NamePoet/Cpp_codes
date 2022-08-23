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
        vector<vector<int>> res;        // ����һ����άvector
        if(!root) {
            return res;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);          // ���Ƚ���������
        bool isOrderLeft = true;

        while(!nodeQueue.empty()) {
            deque<int> levelList;           // ������һ��˫�˶���
            int size = nodeQueue.size();    // size����ǰ��������Ķ��д�С����
                                            // ��ǰ���ڵ�ĸ���
            for (int i=0; i<size; i++) {
                auto node = nodeQueue.front();
                nodeQueue.pop();           // �Ӷ��е�����ǰ���
                if (isOrderLeft) {
                    levelList.push_back(node->val);    // ����Ǵ�������˳�򣬾ͺ����˫�˶���
                } else {
                    levelList.push_front(node->val);   // ����Ǵ�������˳�򣬾�ǰ��������У������Ȳ���2�ٲ���3�õ�3 2
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