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
    vector<vector<int>> levelOrder(TreeNode* root) {    // ��ά���飬(node, level��
        vector<vector<int>> result;       // ÿһ����ӵ�Ԫ��Ҳ��һ������vector
        
        if(root == nullptr)
            return result;
        
        queue<TreeNode*> q;
        q.push(root);       // ��������
        while(!q.empty()) {     // ������в���
            int currentLevelSize = q.size();   // ��ǰ��Ĵ�С���ǵ�ǰ���еĴ�С
            result.push_back(vector<int>());
            for (int i = 1; i <= currentLevelSize; i++) {
                auto node = q.front();      q.pop();  // ����֮ǰ��Ҫ��¼���Ԫ�ص�
                result.back().push_back(node->val);   // ����β�����Ԫ�ص�ֵ
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);

            }
        }

        return result;

    }
};