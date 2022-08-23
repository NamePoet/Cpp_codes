/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // Ҫ��ʱ�临�Ӷ�ΪO(1), ����˳�����ʱ�临�Ӷ�ΪO(n)
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* p;
        // val��Ҫɾ������ֵ

        // �������Ϊ�� or �������ֻ��һ����㣬ɾ��ͷ��㣨Ҳ��β��㣩
        if (head == nullptr) {
            return nullptr;
        }
        
        // ���Ҫɾ���Ľ�㲻��β��㲻��ͷ���
        for (p = head; p != nullptr; p = p->next) {
            if (p->val == val && p->next != nullptr) {
                p->val = p->next->val;
                p->next = p->next->next;
                break;
            } 
            // ���Ҫɾ���Ľ����β���
            else if (p->next->val == val && p->next->next == nullptr){
                p->next = nullptr;
                break;
            }
        }

    
        return head;
    }
};