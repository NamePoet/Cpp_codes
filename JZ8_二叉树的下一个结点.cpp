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
        // 获取根结点
        while(root->next)
            root = root->next;      // 根结点是只有左子结点和右子结点的，没有下一个结点
        
        // 中序遍历用nodes储存所有结点指针
        InOrder(root);
        int n = nodes.size();        // 获得向量的大小（长度）
        
        for (int i=0; i<n-1; i++) {
            TreeLinkNode* cur = nodes[i];
            // 将结点进行匹配
            if(pNode == cur)
            {
                // 如果有匹配到给出的结点，则下一个结点即返回结果
                return nodes[i+1];
            }
        }
            // 否则如果没有下一个结点则返回NULL
            return NULL;
        }
        // 中序遍历
        void InOrder(TreeLinkNode* root) {
            if(root == NULL)  return;
            InOrder(root->left);
            nodes.push_back(root);
            InOrder(root->right);
        }
        
};



/***********************JZ官方题解***************************/
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
        // 如果一个结点有右子树，那么它的下一个结点就是它的右子树中的最左子结点
        pNext = pRight;
    } else if(pNode->m_pParent != nullptr)
        // 如果没有右子树，且该结点是它父结点的左子结点，那么它的下一个结点就是它的父结点 
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while(pParent != nullptr && pCurrent == pParent->m_pRight)
        {
            // 如果一个结点既没有右子树，并且还是它父结点的右子结点，
            // 则沿着指向父结点的指针一直向上遍历，直到找到一个是它父结点的左子结点的结点
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        pNext = pParent;
    }
    return pNext;
}