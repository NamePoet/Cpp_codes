// max - min < 5
// 满足条件：无重复的牌（大小王除外，最大牌-最小牌<5 ）
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int min = 0;
        int max = 14;          // K定义为13
        set<int> s;
        for (int num : nums) {
            if (num != 0)
                s.insert(num);
        }
        min = *s.begin();
        max = *s.rbegin();
        if (max - min < 5)
            return true;
        return false;
    }
};