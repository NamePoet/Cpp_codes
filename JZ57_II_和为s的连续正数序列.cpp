// 枚举 + 暴力
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // 返回值是一个二维vector
        vector<vector<int>> vec;
        vector<int> res;
        int sum = 0, limit = (target - 1) / 2;  // (target - 1) / 2 等效于 target / 2 下取整        
        for (int i = 1; i <= limit; i++) {
            for (int j = i; ; j++) {
                sum += j;
                if (sum > target) {
                    sum = 0;
                    break;
                } else if (sum == target) {
                    res.clear();      // 把size设置成0
                    for (int k = i; k <= j; k++) {
                        res.emplace_back(k);
                    }
                    vec.emplace_back(res);
                    sum = 0;
                    break;
                }
            }
        }
        return vec;
    }
};


// 双指针，优化版的暴力解法
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> vec;
        vector<int> res;
        for (int l = 1, r = 2; l < r;) {
            int sum = (l + r) * (r - l + 1) / 2;      // 经典等差数列求和公式
            if (sum == target) 
            {
                res.clear();
                for (int i = l; i <= r; i++) {
                    res.emplace_back(i);
                }
                vec.emplace_back(res);
                l++;
            } else if (sum < target) {     // 如果和太小，扩展一个更大的数
                r++; 
            } else {                      // 如果和太大，移走最小的数
                l++;
            }
        }
        return vec;
    }
};