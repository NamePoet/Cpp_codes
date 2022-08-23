class MinStack {
    stack<int> x_stack;         // 元素栈，就是每次入栈的元素本身
    stack<int> min_stack;       // 辅助栈，用来存储栈内元素与将要入栈元素之间的最小值
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
        x_stack.pop();       // 弹出栈顶元素，元素栈和辅助栈同时弹出元素
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();         // 返回元素栈中栈顶的值
    }
    
    int min() {
        return min_stack.top();      // 该函数功能是每次返回当前栈中最小元素
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