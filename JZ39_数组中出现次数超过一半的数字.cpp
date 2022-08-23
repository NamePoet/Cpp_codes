#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        // ��ϣ��������[]������������keyֵ��Ӧ��valueֵ
        int majority = 0, cnt = 0;
        for (int num : nums) {          
            // ��ǿforѭ��    for(auto Ԫ�أ����ݼ���)
            ++counts[num];            // key��num    value��counts[num]
                                      // Ԫ��         Ԫ�ض�Ӧ���ֵĴ��� 
            if (counts[num] > cnt) {     // ����жϳ�������counts[num]�ǳ��ֵ�������
                majority = num;          // num�ǳ��ִ�������ֵ
                cnt = counts[num];
            }
        }
        return majority;
    }
};


// ʵ�ʾ���Ͱ���򣬹�ϣ�����������һ���ص������͸��㷺��ͬʱ�±겻��������Ȼ��