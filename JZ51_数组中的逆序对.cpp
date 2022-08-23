#include <vector>
using namespace std;
// 方法一：归并排序
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());       // 创建一个长度为nums.size()的vector
        return mergeSort(0, nums.size()-1, nums, tmp);
    }
private:
    int mergeSort(int l, int r, vector<int>&nums, vector<int>& tmp) {
        // l和r分别是左右指针,也是一个递归算法
        // 终止条件
        if (l >= r) return 0;
        int m = (l + r) / 2;
        int res = mergeSort(l, m, nums, tmp) + mergeSort(m+1, r, nums, tmp);
        // 合并阶段
        int i = l, j = m+1;
        for (int k=l; k<=r; k++) 
            tmp[k] = nums[k];
        for (int k=l; k<=r; k++) 
        {
            if (i == m+1)
                nums[k] = tmp[j++];
            else if (j == r+1 || tmp[i] <= tmp[j])    // 两数比较中，较小的元素需要加入辅助数组中
                nums[k] = tmp[i++];
            else {
                nums[k] = tmp[j++];
                res += m - i + 1;         // 统计逆序对
            }  
        }0
        return res;
    }
};