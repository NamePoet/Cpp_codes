#include <float.h>
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        unsigned int flag = 1;
        while (flag)
        {
            if (n & flag)
                count++;
            
            flag = flag << 1;     // 每次左移一位是表示数字扩大为原来的两倍
        }
        return count;
    }
};




class Solution {
// 把一个整数减去1，再和原整数做与运算，会把该整数最右边的1变成0。那么一个整数的二进制表示中
// 有多少个1，就可以进行多少次这样的操作。
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while (n) {
            ++count;
            n = (n-1)&n;
        }

        return count;
    }
};