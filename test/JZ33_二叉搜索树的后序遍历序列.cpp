#include <vector>
using namespace std;

// 递归分治算法 

class Solution {
public:
    // 如果题目给你的函数参数类型不方便编程就再写一个嵌套函数

    bool verifyPostorder(vector<int>& postorder) {
        return verifyOrder(postorder, 0, postorder.size() - 1);
    }

    bool verifyOrder(vector<int>& postorder, int left, int right) {
        if (left >= right) return true;        // 说明此子树结点数量小于等于1，无需判别，直接返回true
        int i;
        for(i = right; i >= left; i--) {
            if (postorder[i] < postorder[right])  break;        // 此处的postorder[right]是根结点的值
        }
        // 从右向左找到第一个左子节点，记位置为i,找到左右子树的分界线
        for(int j = i; j >= left; j--) {
            if (postorder[j] > postorder[right]) return false;
        }
        // 从左子结点向左遍历看是否都小于根结点，如果不是的话，说明不是后序遍历

        return verifyOrder(postorder, left, i) && verifyOrder(postorder, i+1, right - 1);
        // 再分别对左子树、右子树进行遍历，看是否子树的子树也满足二叉搜索树的定义
    }


};