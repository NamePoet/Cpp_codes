/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    vector<TreeLinkNode*> nodes;
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        TreeLinkNode* root = pNode;
        // ��ȡ�����
        while(root->next)
            root = root->next;      // �������ֻ�����ӽ������ӽ��ģ�û����һ�����
        
        // ���������nodes�������н��ָ��
        InOrder(root);
        int n = nodes.size();        // ��������Ĵ�С�����ȣ�
        
        for (int i=0; i<n-1; i++) {
            TreeLinkNode* cur = nodes[i];
            // ��������ƥ��
            if(pNode == cur)
            {
                // �����ƥ�䵽�����Ľ�㣬����һ����㼴���ؽ��
                return nodes[i+1];
            }
        }
            // �������û����һ������򷵻�NULL
            return NULL;
        }
        // �������
        void InOrder(TreeLinkNode* root) {
            if(root == NULL)  return;
            InOrder(root->left);
            nodes.push_back(root);
            InOrder(root->right);
        }
        
};



/***********************JZ�ٷ����***************************/
BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if(pNode == nullptr)
        return nullptr;
    
    BinaryTreeNode* pNext = nullptr;
    if(pNode->m_pRight != nullptr)
    {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while(pRight->m_pLeft != nullptr)
            pRight = pRight->m_pLeft;
        // ���һ�����������������ô������һ�������������������е������ӽ��
        pNext = pRight;
    } else if(pNode->m_pParent != nullptr)
        // ���û�����������Ҹý���������������ӽ�㣬��ô������һ�����������ĸ���� 
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while(pParent != nullptr && pCurrent == pParent->m_pRight)
        {
            // ���һ������û�������������һ��������������ӽ�㣬
            // ������ָ�򸸽���ָ��һֱ���ϱ�����ֱ���ҵ�һ���������������ӽ��Ľ��
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        pNext = pParent;
    }
    return pNext;
}