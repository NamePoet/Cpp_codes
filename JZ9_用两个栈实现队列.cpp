#include <float.h>
class CQueue {
    private:
        stack<int> inStack, outStack;

        void in2out() {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
public:
    CQueue() {

    }
    
    void appendTail(int value) {        // ������Ԫ�ط���inStack���ջ
        inStack.push(value);            // appendtailû�з���ֵ�������NULL
    }
    
    int deleteHead() {
        if (outStack.empty()) {
            if (inStack.empty()) {
                return -1;            // ����ջ��Ϊ�գ��򷵻�-1���������쳣����
            }
            in2out();                  // ջ1�е�Ԫ��ת�Ƶ�ջ2��
        }
        int value = outStack.top();
        outStack.pop();
        return value;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */