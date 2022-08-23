// ��̬�滮�ⷨ --- ��̵�˼ά
class Solution {
public:
    int cuttingRope(int n) {    // n�����ӵ�ԭ��
        if (n <= 3)
            return n-1;
        
        int* products = new int[n+1];      // �¶���һ���������飬����Ϊn+1
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


// ̰���㷨 --- ��ʵ����ѧ���������Ƶ����̺ܸ���
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        
        // �����ܶ�ؼ�ȥ����Ϊ3�����Ӷ�
        int timesOf3 = n / 3;

        // ���������ʣ�µĳ���Ϊ4��ʱ�򣬲����ټ�ȥ����Ϊ3�����Ӷ�

        // ��ʱ���õķ����ǰ����Ӽ��ɳ���Ϊ2�����Σ���Ϊ2*2>3*1
        if (n - timesOf3*3 == 1)
            timesOf3 -= 1;

        int timesOf2 = (n - timesOf3*3) / 2;

        return (int)(pow(3, timesOf3) * (int) (pow(2, timesOf2)));        
    }
};