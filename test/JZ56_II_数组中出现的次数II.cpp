// ��ϣ����
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;        // ��ϣ��

        for (int n: nums) map[n]++;         // ��¼����

        for (int n: nums)
            if (map[n] == 1) 
                return n;
        
        return 0;
    }
};