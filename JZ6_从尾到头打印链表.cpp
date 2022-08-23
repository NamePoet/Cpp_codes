/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 栈的方法

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        stack<ListNode*>nodes;     // 创建一个名为nodes的栈
        ListNode* pNode = head;
        while (pNode != nullptr)
        {
            nodes.push(pNode);   // 将头节点入栈
            pNode = pNode->next; // 遍历下一个结点
        }
        // 全部结点入栈完毕
        // 从栈顶开始打印
        while(!nodes.empty())    // 如果当前栈不为空
        {
            pNode = nodes.top();            // 取栈顶的结点
            result.push_back(pNode->val);
            // push_back()函数表示向尾部插入数字
            // 将栈顶结点的值加入到vector中
            nodes.pop();                    // 栈顶结点出栈
        }
        return result;
    }
};

// 递归的方法
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