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
    
    void appendTail(int value) {        // 将所给元素放入inStack这个栈
        inStack.push(value);            // appendtail没有返回值，即输出NULL
    }
    
    int deleteHead() {
        if (outStack.empty()) {
            if (inStack.empty()) {
                return -1;            // 两个栈都为空，则返回-1————异常处理
            }
            in2out();                  // 栈1中的元素转移到栈2中
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