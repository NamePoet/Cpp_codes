// ö�� + ����
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // ����ֵ��һ����άvector
        vector<vector<int>> vec;
        vector<int> res;
        int sum = 0, limit = (target - 1) / 2;  // (target - 1) / 2 ��Ч�� target / 2 ��ȡ��        
        for (int i = 1; i <= limit; i++) {
            for (int j = i; ; j++) {
                sum += j;
                if (sum > target) {
                    sum = 0;
                    break;
                } else if (sum == target) {
                    res.clear();      // ��size���ó�0
                    for (int k = i; k <= j; k++) {
                        res.emplace_back(k);
                    }
                    vec.emplace_back(res);
                    sum = 0;
                    break;
                }
            }
        }
        return vec;
    }
};


// ˫ָ�룬�Ż���ı����ⷨ
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> vec;
        vector<int> res;
        for (int l = 1, r = 2; l < r;) {
            int sum = (l + r) * (r - l + 1) / 2;      // ����Ȳ�������͹�ʽ
            if (sum == target) 
            {
                res.clear();
                for (int i = l; i <= r; i++) {
                    res.emplace_back(i);
                }
                vec.emplace_back(res);
                l++;
            } else if (sum < target) {     // �����̫С����չһ���������
                r++; 
            } else {                      // �����̫��������С����
                l++;
            }
        }
        return vec;
    }
};