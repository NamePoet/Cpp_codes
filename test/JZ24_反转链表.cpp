
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pReversedHead = nullptr;
        ListNode* pNode = head;
        ListNode* pPrev = nullptr;
        while(pNode != nullptr)
        {
            ListNode* pNext = pNode->next;

            if (pNext == nullptr)   
            {
                pReversedHead = pNode;      // 此时pNode到了尾结点
            }

            pNode->next = pPrev;        // 断开连接
            pPrev = pNode;
            pNode = pNext;

        }
        
        return pReversedHead;

    }   
};