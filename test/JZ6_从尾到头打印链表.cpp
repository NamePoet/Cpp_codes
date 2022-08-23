/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// ջ�ķ���

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        stack<ListNode*>nodes;     // ����һ����Ϊnodes��ջ
        ListNode* pNode = head;
        while (pNode != nullptr)
        {
            nodes.push(pNode);   // ��ͷ�ڵ���ջ
            pNode = pNode->next; // ������һ�����
        }
        // ȫ�������ջ���
        // ��ջ����ʼ��ӡ
        while(!nodes.empty())    // �����ǰջ��Ϊ��
        {
            pNode = nodes.top();            // ȡջ���Ľ��
            result.push_back(pNode->val);
            // push_back()������ʾ��β����������
            // ��ջ������ֵ���뵽vector��
            nodes.pop();                    // ջ������ջ
        }
        return result;
    }
};

// �ݹ�ķ���
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if(!head)
            return {};
        vector<int> a=reversePrint(head->next);
        a.push_back(head->val);
        return a;
    }
};