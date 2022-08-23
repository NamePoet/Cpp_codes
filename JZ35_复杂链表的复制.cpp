#include<cstdio>
#include <unordered_map>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// ���� + ��ϣ��
class Solution {
public:
    unordered_map<Node*, Node*> cachedNode;      // Ӣ�ĺ����Ǳ����������Ľ��

    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        
        if(!cachedNode.count(head)) {
            Node* headNew = new Node(head->val);
            // ���ٵĿռ��ָ��ÿռ��ָ���������Ҫ��ͬ
            cachedNode[head] = headNew;        // ԭ�����½ڵ��ֵ�γ�ӳ���ϵ
            headNew->next = copyRandomList(head->next);  
            // �ݹ����������
            headNew->random = copyRandomList(head->random);

        }
        return cachedNode[head];
    }
};