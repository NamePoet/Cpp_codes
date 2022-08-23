
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
                pReversedHead = pNode;      // ��ʱpNode����β���
            }

            pNode->next = pPrev;        // �Ͽ�����
            pPrev = pNode;
            pNode = pNext;

        }
        
        return pReversedHead;

    }   
};