#include <queue>
using namespace std;

// ��������С�� ����
class MedianFinder {
// ��С�ѵ�Ԫ�ض�Ҫ�����ѵ�Ԫ�ظ���������ѣ��ұ���С��


public:
    priority_queue<int, vector<int>, less<int>> queMin;     // ��С��
    priority_queue<int, vector<int>, greater<int>> queMax;  // ����
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    // ����ǳ��ü���׶�
    // �ں���������������������Ԫ�أ�����С�ѱ����Ѷ�һ��Ԫ��
    // ż����Ԫ�أ������

    void addNum(int num) {
        if (queMin.empty() || num <= queMin.top()) {
            queMin.push(num);
            // ������������֮��ܳ���1����֤ƽ������
            if (queMax.size() + 1 < queMin.size()) {
                queMax.push(queMin.top());      // ���Ҳ���С�����������������
                queMin.pop();           // ���������ӣ��൱�ڽ������ұ������ת��
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

