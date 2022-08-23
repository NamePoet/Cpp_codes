#include <vector>
using namespace std;

// 左右乘积数组
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.size() == 0) 
            return {};
        int length = a.size();

        // L和R分别表示左右两侧的乘积列表, 长度均为length, 初值均为0
        vector<int> L(length, 0), R(length, 0);

        vector<int> answer(length);

        // L[i]为索引i左侧所有元素的乘积
        // 对于索引为'0'的元素，因为左侧没有元素，所以L[0] = 1;
        L[0] = 1;
        for (int i=1; i<length; i++) 
        {
            L[i] = a[i-1] * L[i-1];           // 实质也是递归的思想
        }

        // R[i]为索引i右侧所有元素的乘积
        // 对于索引为'length-1'的元素。因为右侧没有元素。所以R[length-1] = 1
        R[length-1] = 1;
        for (int i=length-2; i>=0; i--) 
        {
            R[i] = a[i+1] * R[i+1];
        }

        // 对于索引i，除a[i]之外其余元素就是左侧所有元素乘积乘以右侧所有元素乘积

        for (int i=0; i<length; i++) {
            answer[i] = L[i] * R[i];
        }

        return answer;
    }
};



// 优化空间的左右相乘算法
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.size() == 0) 
            return {};
        int length = a.size();
        vector<int> answer(length);

        // answer[i] 表示索引 i 左侧所有元素的乘积
        // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
        answer[0] = 1;
        for (int i=1; i<length; i++) {
            answer[i] = a[i-1] * answer[i-1];
        }

        // R 为右侧所有元素的乘积
        // 刚开始右边没有元素，所以 R = 1
        R = 1;
        for (int i=length-1; i>=0; i--) {
            // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
            answer[i] = answer[i] * R;
            // R需要包括右边所有的乘积，所以计算下一个结果时需要将当前值乘到R上
            R *= a[i];

        }
        return answer;
    }
};