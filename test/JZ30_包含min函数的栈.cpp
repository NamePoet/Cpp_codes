class MinStack {
    stack<int> x_stack;         // Ԫ��ջ������ÿ����ջ��Ԫ�ر���
    stack<int> min_stack;       // ����ջ�������洢ջ��Ԫ���뽫Ҫ��ջԪ��֮�����Сֵ
public:
    /** initialize your data structure here. */
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        min_stack.push(::min(min_stack.top(), x));   
    }
    
    void pop() {
        x_stack.pop();       // ����ջ��Ԫ�أ�Ԫ��ջ�͸���ջͬʱ����Ԫ��
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();         // ����Ԫ��ջ��ջ����ֵ
    }
    
    int min() {
        return min_stack.top();      // �ú���������ÿ�η��ص�ǰջ����СԪ��
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */