/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 要求时间复杂度为O(1), 常规顺序查找时间复杂度为O(n)
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* p;
        // val是要删除结点的值

        // 如果链表为空 or 如果链表只有一个结点，删除头结点（也是尾结点）
        if (head == nullptr) {
            return nullptr;
        }
        
        // 如果要删除的结点不是尾结点不是头结点
        for (p = head; p != nullptr; p = p->next) {
            if (p->val == val && p->next != nullptr) {
                p->val = p->next->val;
                p->next = p->next->next;
                break;
            } 
            // 如果要删除的结点是尾结点
            else if (p->next->val == val && p->next->next == nullptr){
                p->next = nullptr;
                break;
            }
        }

    
        return head;
    }
};