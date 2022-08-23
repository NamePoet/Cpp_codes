#include <vector>
using namespace std;

// 任何一个数字异或它自己都等于0
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for (int n:nums)
            ret ^= n;       // 异或操作
        int div = 1;
        while ((div & ret) == 0) 
            div <<= 1;
        int a = 0, b = 0;
        for (int n:nums)
            if (div & n) 
                a ^= n;
            else
                b ^= n;
        return vector<int> {a,b};
    }
};


// 任何一个数与0“异或运算”是其本身 —— 本身与本身异或是0
// 任何一个数与其本身“与运算”是其本身

// 1可以作为一个很重要的与运算因子，与偶数“与运算”是0，与奇数“与运算”是1