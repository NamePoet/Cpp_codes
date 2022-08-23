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
            return false;               // ��������ĸ����ֵ��ͬ���ͱ�ʾ����������

        // �����ǵݹ�������������Ƿ�һ��
        return DoesTree_AHaveTree_B(A->left, B->left) && DoesTree_AHaveTree_B(A->right, B->right);
    }

    bool Equal(double num1, double num2)
    {
        if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))  
            return true;
            // ��������Ĳ�ľ���ֵС��һ����С�������Ϳ�����Ϊ�������
        else 
            return false;
    }


public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        // �ȶ���B����A������
        bool result = false;

        if(A != nullptr && B != nullptr)        // ������һ���쳣����
        {
            if(Equal(A->val, B->val))
                result = DoesTree_AHaveTree_B(A, B);
            if(!result)
                // Ѱ��A�Ƿ�����������ͬ��ֵ
                result = isSubStructure(A->left, B);
            if(!result)
                result = isSubStructure(A->right, B);
        }

        return result;

    }
};