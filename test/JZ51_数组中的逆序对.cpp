#include <vector>
using namespace std;
// ����һ���鲢����
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());       // ����һ������Ϊnums.size()��vector
        return mergeSort(0, nums.size()-1, nums, tmp);
    }
private:
    int mergeSort(int l, int r, vector<int>&nums, vector<int>& tmp) {
        // l��r�ֱ�������ָ��,Ҳ��һ���ݹ��㷨
        // ��ֹ����
        if (l >= r) return 0;
        int m = (l + r) / 2;
        int res = mergeSort(l, m, nums, tmp) + mergeSort(m+1, r, nums, tmp);
        // �ϲ��׶�
        int i = l, j = m+1;
        for (int k=l; k<=r; k++) 
            tmp[k] = nums[k];
        for (int k=l; k<=r; k++) 
        {
            if (i == m+1)
                nums[k] = tmp[j++];
            else if (j == r+1 || tmp[i] <= tmp[j])    // �����Ƚ��У���С��Ԫ����Ҫ���븨��������
                nums[k] = tmp[i++];
            else {
                nums[k] = tmp[j++];
                res += m - i + 1;         // ͳ�������
            }  
        }0
        return res;
    }
};