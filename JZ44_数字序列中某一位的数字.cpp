#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {         // 参数给的是第n位，求第n位对应的数字
        //当n=0不存在。  
        //分段
        //第一段（1-9）数字1-10 个，长度 9*1
        //第二端（10-99）数字(100-10)个，长度（100-10）*2 = 90*2
        //第三段（100-999）数字(1000-100)个, 长度（1000-100）*3 =900*3

        // n = 1, 返回1。n=10对应第二段的第一个数字10。取第一位为1

        int i = 1;   // 分段，第1段开始

        while(n > 9*pow(10, i-1) * i)    // 找到i在第几段，如第二段有90*2个字符
        {
            n = n - 9*pow(10, i-1) * i;
            i++;
        }   

        // 此处知道该数字位于第几段，是这一段的第几个字符

        int min_num = pow(10, i-1);     // 这一段的最小值。比如第二段，最小为10
        int cur_num = min_num + (n-1)/i;           // 得出该数字是这一段的哪个数字  第0数字是它本身
        int cur_bit = (n-1)%i;          // 得出是这个数字的哪一位，第0位为最高位，第1位位次高位

        string s = to_string(cur_num);
        return s[cur_bit]-'0';       // 返回这一位的数字
    
    
    
    }
};