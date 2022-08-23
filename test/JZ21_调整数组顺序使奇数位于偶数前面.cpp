class Solution {
public:
    // C++的指针其实可以通过定义变量来作为数组元素的下标来操作元素
    vector<int> exchange(vector<int>& nums) {      // 直接可以操作nums数组
    {
        int i = 0, j = nums.size()-1;
        while (i < j)
        {
            while(i < j && (nums[i] & 1) == 1 ) i++;     // 当它能出循环的时候说明定位到了偶数
            while(i < j && (nums[j] & 1) == 0 ) j--;     // 出循环的时候说明定位到了奇数
            swap(nums[i], nums[j]);  
        }

        return nums;
    }
    }
};