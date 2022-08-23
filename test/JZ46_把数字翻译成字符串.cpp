// 滚动数组 ———— 动态规划的优化方案

#include <string>
using namespace std;
class Solution {
public:
    int translateNum(int num) {
        string src = to_string(num);     // 将整数转换成字符串存入src中
        int p = 0, q = 0, r = 1;
        for (int i = 0; i <src.size(); i++) {
            p = q;
            q = r;
            r = 0;
            r += q;
            if (i == 0) {
                continue;
            }
            auto pre = src.substr(i-1, 2);
            if (pre <= "25" && pre >= "10") {
                r += p;
            }
        } 
        return r;
    }
};