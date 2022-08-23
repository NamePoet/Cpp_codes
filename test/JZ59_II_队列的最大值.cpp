// 暴力法
class MaxQueue {
    int q[20000];
    int begin = 0, end = 0;
public:
    MaxQueue() {    
    }
    
    int max_value() {
        int ans = -1;
        for (int i = begin; i != end; i++) {
            ans = max(ans, q[i]);
        }
        return ans;
    }
    
    void push_back(int value) {
        q[end++] = value;
    }
    
    int pop_front() {
        if (begin == end)
            return -1;
        return q[begin++];
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */



 // 维护一个单调的双端队列  （保持单调递减）
 class MaxQueue {
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (d.empty())
            return -1;
        return d.front();           // 队首元素即最大值
    }
    
    void push_back(int value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
            // 保证每个元素前面没有比它小的数字

        }

        d.push_back(value);
        q.push(value);

    }
    
    int pop_front() {
        if (q.empty()) 
            return -1;
        int ans = q.front();
        if (ans == d.front()) {
            d.pop_front();
        }
        q.pop();
        return ans;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */