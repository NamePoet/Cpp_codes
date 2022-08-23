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



// DFS�����������
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;          // ���·����Ԫ�ص�����vector

    void dfs(TreeNode* root, int target)
    {
        if(root == nullptr) {
            return;
        }
        path.emplace_back(root->val);
        target -= root->val;
        // ��������ֻ��һ������㣬ǡ��Ҳ�Ƕ�Ӧtarget��ֵ��ֱ�ӽ���path����ret�����ά������
        if(root->left == nullptr && root->right == nullptr && target == 0)
        {
            // �����Ǳ�ʾ��������Ҷ�ڵ㣬�Ϳ��Է���path��
            ret.emplace_back(path);
        }
        dfs(root->left, target);     // һ���߽�һ���ݹ麯�������û���ߵ���ֹ�����ǲ����������������
        dfs(root->right, target);
        path.pop_back();           // �������ܹؼ���ɾ��ջĩβ����һ��Ԫ��
    }




    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return ret;
    }
};