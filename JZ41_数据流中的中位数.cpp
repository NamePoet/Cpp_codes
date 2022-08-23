#include <queue>
using namespace std;

// 方法：最小堆 最大堆
class MedianFinder {
// 最小堆的元素都要比最大堆的元素更大，左边最大堆，右边最小堆


public:
    priority_queue<int, vector<int>, less<int>> queMin;     // 最小堆
    priority_queue<int, vector<int>, greater<int>> queMax;  // 最大堆
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    // 代码非常得简洁易懂
    // 内含两种情况，如果是奇数个元素，则最小堆比最大堆多一个元素
    // 偶数个元素，则均分

    void addNum(int num) {
        if (queMin.empty() || num <= queMin.top()) {
            queMin.push(num);
            // 两个堆中数据之差不能超过1，保证平均分配
            if (queMax.size() + 1 < queMin.size()) {
                queMax.push(queMin.top());      // 把右侧最小的数插入左边最大堆中
                queMin.pop();           // 将该数出队，相当于将数从右边向左边转移
            }
        } else {
            queMax.push(num);
            if (queMax.size() > queMin.size()) {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }
    
    double findMedian() {
        if (queMin.size() > queMax.size()) {
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    } 
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

