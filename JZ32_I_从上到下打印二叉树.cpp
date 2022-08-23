#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ÿ�δ�ӡһ������ʱ������ý�����ӽ�㣬��Ѹý����ӽ��ŵ�һ�����е�ĩβ��
// �����������е�ͷ��ȡ�����������еĽ�㣬�ظ�ǰ��Ĵ�ӡ������ֱ�����������еĽ�㶼
// ����ӡ����


class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
        
        deque<TreeNode*> d;
        d.push_back(root);

        while(d.size())
        {
            TreeNode* pNode = d.front();
            d.pop_front();
            result.push_back(pNode->val);         // ������Ԫ�ؾʹ����vector��

            if(pNode->left)
                d.push_back(pNode->left);
            if(pNode->right)
                d.push_back(pNode->right);
        }

        return result;
        
    }
};

// ������������������Ǳ�������㣬Ȼ��ݹ������ӽ��