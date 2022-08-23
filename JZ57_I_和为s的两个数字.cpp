#include <vector>
using namespace std;


// �����������
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*����˫ָ��*/      // Ҳ�ƶ�ײ˫ָ��
        int left = 0;
        int right = nums.size()-1;

        /*��������*/
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                return {nums[left], nums[right]};
            }
        }
        return {};
    }
};


// set��������
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*����set�����洢����*/
        unordered_set<int> st;        // ����Ĺ�ϣ���ϣ�����������δ��������
        for (int i=0; i<nums.size(); i++) {
            if (st.find(nums[i]) != st.end()) {
                return {(target-nums[i]), nums[i]};
            }
            else {
                st.insert(target-nums[i]);
            }
        }
        return {};
    }
};