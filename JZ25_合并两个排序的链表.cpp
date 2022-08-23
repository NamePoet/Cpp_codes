struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 


 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;

        ListNode* pMergedHead, *p1, *p2;
        if (l1->val < l2->val) {
            pMergedHead = l1;
            pMergedHead->next = mergeTwoLists(l1->next, l2);
            // 递归思路非常巧妙

        } else if(l1->val > l2->val)
        {
            pMergedHead = l2;
            pMergedHead->next = mergeTwoLists(l1, l2->next);
 
       }

        return pMergedHead;    
    }
}; 