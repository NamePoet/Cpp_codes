
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
    // �ҵĴ������˫ָ����ʼ��Ӧ��Ҫ��һ������Ȼ��һֱ��ѭ������
private:
    ListNode* MeetingNode(ListNode* pHead)
    {
        if(pHead == nullptr)
            return nullptr;                 // ����Ϊ�յ��쳣����
        
        ListNode* pSlow = pHead->next;
        if(pSlow == nullptr)
            return nullptr;                 // ����Ϊ�յ��쳣����
        
        ListNode* pFast = pSlow->next;
        while(pFast != nullptr && pSlow != nullptr)
        {
            if(pFast == pSlow)                 // �������������ܹ�������ʾ���Ǵ���������
                return pFast;
            
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pFast!=nullptr)
                pFast=pFast->next;            // ����ÿ�λ�������������һ��
        }

        return nullptr;
    }
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* meetingNode = MeetingNode(pHead);      // meetingNode�᷵�������Ľ��λ��
        if(meetingNode == nullptr)
            return nullptr;            // ��ʾ���Ǹ��޻�����
        
        // �õ����н����Ŀ
        int nodesInLoop = 1;
        ListNode* pNode1 = meetingNode;
        while(pNode1->next != meetingNode)
        {
            pNode1 = pNode1->next;
            ++nodesInLoop;                     // �˴��͵õ��˻��н����Ŀ
        }

        // ���ƶ�pNode1, ����Ϊ���н�����Ŀ
        pNode1 = pHead;
        for(int i=0; i<nodesInLoop; ++i)
            pNode1 = pNode1->next;
        
        // ���ƶ�pNode1��pNode2
        ListNode* pNode2 = pHead;
        while(pNode1 != pNode2)
        {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }

        return pNode1;
    }
};