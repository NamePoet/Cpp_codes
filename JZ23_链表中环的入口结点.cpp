
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
    // 我的错误就是双指针起始点应该要差一个，不然就一直在循环里了
private:
    ListNode* MeetingNode(ListNode* pHead)
    {
        if(pHead == nullptr)
            return nullptr;                 // 链表为空的异常处理
        
        ListNode* pSlow = pHead->next;
        if(pSlow == nullptr)
            return nullptr;                 // 链表为空的异常处理
        
        ListNode* pFast = pSlow->next;
        while(pFast != nullptr && pSlow != nullptr)
        {
            if(pFast == pSlow)                 // 如果快慢两结点能够相遇表示这是带环的链表
                return pFast;
            
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pFast!=nullptr)
                pFast=pFast->next;            // 快结点每次会走两步，多走一步
        }

        return nullptr;
    }
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* meetingNode = MeetingNode(pHead);      // meetingNode会返回相遇的结点位置
        if(meetingNode == nullptr)
            return nullptr;            // 表示这是个无环链表
        
        // 得到环中结点数目
        int nodesInLoop = 1;
        ListNode* pNode1 = meetingNode;
        while(pNode1->next != meetingNode)
        {
            pNode1 = pNode1->next;
            ++nodesInLoop;                     // 此处就得到了环中结点数目
        }

        // 先移动pNode1, 次数为环中结点的数目
        pNode1 = pHead;
        for(int i=0; i<nodesInLoop; ++i)
            pNode1 = pNode1->next;
        
        // 再移动pNode1和pNode2
        ListNode* pNode2 = pHead;
        while(pNode1 != pNode2)
        {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }

        return pNode1;
    }
};