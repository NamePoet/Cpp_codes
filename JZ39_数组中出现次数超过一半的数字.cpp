#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        // 哈希表：可以用[]操作符来访问key值对应的value值
        int majority = 0, cnt = 0;
        for (int num : nums) {          
            // 增强for循环    for(auto 元素：数据集合)
            ++counts[num];            // key：num    value：counts[num]
                                      // 元素         元素对应出现的次数 
            if (counts[num] > cnt) {     // 如果判断成立，则counts[num]是出现的最大次数
                majority = num;          // num是出现次数最大的值
                cnt = counts[num];
            }
        }
        return majority;
    }
};


// 实质就是桶排序，哈希表优于数组的一个特点是类型更广泛，同时下标不仅限于自然数