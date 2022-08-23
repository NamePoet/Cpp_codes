#include <vector>
#include <algorithm>
using namespace std;
// 动态规划算法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {   // 遍历这个向量中的元素
            pre = max(pre+x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;

    }
};