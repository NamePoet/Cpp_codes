#include <string>
using namespace std;


class Solution {
public:
    int strToInt(string str) {
        int start = 0;
        int n = str.size();
        while(start < n && str[start] == ' ') start++;
        int sign = 1;
        if(start < n && str[start] == '-' || str[start] == '+'){
            sign = str[start] == '-' ? -1 : 1;
            start++;
        }
        int num = 0;
        while(start < n && isdigit(str[start])){
            if(sign == 1 && num > (INT_MAX - (str[start] - '0')) / 10) return INT_MAX;
            if(sign == -1 && num < (INT_MIN +  (str[start] - '0')) / 10) return INT_MIN;
            num = num * 10 + (str[start] - '0') * sign;
            start++;
        }
        return num;
    }
};