class Solution {
public:
    // fib这个函数是写在公有类里面的
    int fib(int n) {
        int result[2] = {0,1};
        if(n < 2)
            return result[n];
        long long fibNMinusOne = 0;
        long long fibNMinusTwo = 1;
        long long fibN = 0;
        for(unsigned int i=2; i<=n; i++)
        {
            fibN = (fibNMinusOne + fibNMinusTwo) % 1000000007;
            fibNMinusOne = fibNMinusTwo;
            fibNMinusTwo = fibN;
        }
        return fibN;         // 会栈溢出，n = 95就不行了
    }
};


/*
class Solution {
public:
    int fib(int n) {
        int MOD = 1000000007;
        if (n < 2) {
            return n;
        }
        int p = 0, q = 0, r = 1;
        for (int i = 2; i <= n; ++i) {
            p = q; 
            q = r; 
            r = (p + q)%MOD;
        }
        return r;
    }
};


*/