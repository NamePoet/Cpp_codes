#include <algorithm>
#include <vector>
using namespace std;
// �����㷨
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() + 1;
        for (int i=0; i<n-1; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n-1; 
    }
};


// ��ϣ���Ϸ�
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> set;
        int n = nums.size() + 1;
        for (int i=0; i<n-1; i++) {
            set.insert(nums[i]);
        }
        int missing = -1;
        for (int i=0; i<=n-1; i++) {
            if (!set.count(i)) {
                missing = i;
                break;
            }   
        }
        return missing;
    }
};


// λ����
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size() + 1;
        for (int i = 0; i < n - 1; i++) {
            res ^= nums[i];
        }
        for (int i = 0; i <= n - 1; i++) {
            res ^= i;
        }
        return res;
    }
};

