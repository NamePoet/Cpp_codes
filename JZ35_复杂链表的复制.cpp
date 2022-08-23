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

// 回溯 + 哈希表
class Solution {
public:
    unordered_map<Node*, Node*> cachedNode;      // 英文含义是被贮存起来的结点

    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        
        if(!cachedNode.count(head)) {
            Node* headNew = new Node(head->val);
            // 开辟的空间和指向该空间的指针的类型需要相同
            cachedNode[head] = headNew;        // 原结点和新节点的值形成映射关系
            headNew->next = copyRandomList(head->next);  
            // 递归完成链表复制
            headNew->random = copyRandomList(head->random);

        }
        return cachedNode[head];
    }
};