#include <vector>
#include <algorithm>
using namespace std;
// ��̬�滮�㷨
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {   // ������������е�Ԫ��
            pre = max(pre+x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;

    }
};