#include <vector>
using namespace std;

// �κ�һ������������Լ�������0
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for (int n:nums)
            ret ^= n;       // ������
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


// �κ�һ������0��������㡱���䱾�� ���� �����뱾�������0
// �κ�һ�������䱾�������㡱���䱾��

// 1������Ϊһ������Ҫ�����������ӣ���ż���������㡱��0���������������㡱��1