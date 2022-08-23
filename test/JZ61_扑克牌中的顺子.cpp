// max - min < 5
// �������������ظ����ƣ���С�����⣬�����-��С��<5 ��
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int min = 0;
        int max = 14;          // K����Ϊ13
        set<int> s;
        for (int num : nums) {
            if (num != 0)
                s.insert(num);
        }
        min = *s.begin();
        max = *s.rbegin();
        if (max - min < 5)
            return true;
        return false;
    }
};