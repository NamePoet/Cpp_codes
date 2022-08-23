// 动态规划解法 --- 编程的思维
class Solution {
public:
    int cuttingRope(int n) {    // n是绳子的原长
        if (n <= 3)
            return n-1;
        
        int* products = new int[n+1];      // 新定义一个整型数组，长度为n+1
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;

        int max = 0;
        for (int i=4; i<=n; i++)
        {
            max = 0;
            for (int j = 1; j <= i/2; j++)
            {
                int product = products[j] * products[i - j];
                if(max < product)
                    max = product;
                

                products[i] = max;
                

            }
        }
        max = products[n];
        delete[] products;

        return max;
    }
};


// 贪婪算法 --- 扎实的数学基本功，推导过程很复杂
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        
        // 尽可能多地剪去长度为3的绳子段
        int timesOf3 = n / 3;

        // 当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段

        // 此时更好的方法是把绳子剪成长度为2的两段，因为2*2>3*1
        if (n - timesOf3*3 == 1)
            timesOf3 -= 1;

        int timesOf2 = (n - timesOf3*3) / 2;

        return (int)(pow(3, timesOf3) * (int) (pow(2, timesOf2)));        
    }
};