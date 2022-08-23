// 哈希表方法
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;        // 哈希表

        for (int n: nums) map[n]++;         // 记录次数

        for (int n: nums)
            if (map[n] == 1) 
                return n;
        
        return 0;
    }
};