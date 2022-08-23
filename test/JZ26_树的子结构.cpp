struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 


class Solution {
private:
    bool DoesTree_AHaveTree_B(TreeNode* A, TreeNode* B)
    {
        if(B == nullptr)
            return true;
        if(A == nullptr)
            return false;
        
        if(!Equal(A->val, B->val))
            return false;               // 如果两树的根结点值不同，就表示不存在子树

        // 下面是递归查找左、右子树是否一致
        return DoesTree_AHaveTree_B(A->left, B->left) && DoesTree_AHaveTree_B(A->right, B->right);
    }

    bool Equal(double num1, double num2)
    {
        if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))  
            return true;
            // 如果两数的差的绝对值小于一个很小的数，就可以认为它们相等
        else 
            return false;
    }


public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        // 先定义B不是A的子树
        bool result = false;

        if(A != nullptr && B != nullptr)        // 首先做一个异常处理
        {
            if(Equal(A->val, B->val))
                result = DoesTree_AHaveTree_B(A, B);
            if(!result)
                // 寻找A是否还有与根结点相同的值
                result = isSubStructure(A->left, B);
            if(!result)
                result = isSubStructure(A->right, B);
        }

        return result;

    }
};