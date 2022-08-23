#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 每次打印一个结点的时候，如果该结点有子结点，则把该结点的子结点放到一个队列的末尾。
// 接下来到队列的头部取出最早进入队列的结点，重复前面的打印操作，直至队列中所有的结点都
// 被打印出来


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
            result.push_back(pNode->val);         // 弹出的元素就存放入vector中

            if(pNode->left)
                d.push_back(pNode->left);
            if(pNode->right)
                d.push_back(pNode->right);
        }

        return result;
        
    }
};

// 所有树的题无外乎都是遍历根结点，然后递归左右子结点