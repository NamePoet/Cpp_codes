
 //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *p1, *p2;
        int cnt = 0;
        int flag = 0;
        if (head == nullptr || k == 0)
            return nullptr;
        
        for (p1 = head; p1 != nullptr; p1 = p1->next)
        {
            if(cnt == k-1 && !flag) 
            {
                p2 = head;
                flag = 1;
                continue;
            }
            else
            {
                cnt++;
            }
            
            if (flag) {
                p2 = p2->next;
            }
        }
        return p2;
    }
};