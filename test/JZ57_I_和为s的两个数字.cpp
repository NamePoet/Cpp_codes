#include <vector>
using namespace std;


// 已排序的数组
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*定义双指针*/      // 也称对撞双指针
        int left = 0;
        int right = nums.size()-1;

        /*遍历查找*/
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


// set容器方法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*定义set容器存储数据*/
        unordered_set<int> st;        // 无序的哈希集合，适用于数组未排序的情况
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