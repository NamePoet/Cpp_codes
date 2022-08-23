#include <float.h>
class Solution {
public:
    double myPow(double x, int n) {    // x为底数，n为指数
        bool invalid_input = false;
        if (equal(x,0.0) && n < 0)
        {
            invalid_input = true;
            return 0.0;
        } 

        unsigned int absExponent = (unsigned int) (n);      // 记录指数的绝对值
        if (n < 0)
            absExponent = (unsigned int) -n;
        
        double result = PowerWithUnsignedExponent(x, n);

        if (n < 0)
            result = 1.0 / result;

        return result;
    }

    double PowerWithUnsignedExponent(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        
        double result = PowerWithUnignedExponent(x, n>>1);
        result *= result;
        if (n & 0x1 == 1)
            result *= x;

        return result;
    }

};