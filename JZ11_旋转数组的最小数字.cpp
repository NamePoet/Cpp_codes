// 二分查找法
// 用两个指针分别指向数组的第一个元素和最后一个元素，按照旋转规则，第一个元素应该是大于或者
// 等于最后一个元素的

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0;
        int high = numbers.size() - 1;
        // 定义两个“指针”，实际是数组下标
        while (low < high) {
            int mid = (low + high) / 2;
            if(numbers[mid] > numbers[high])
            {
                low = mid+1;
            } else if(numbers[mid] < numbers[high]) {
                high = mid;
            }
            else{
                high -=1;             // 这步很关键，有重复数字时，定位到最中间那个数
            }         
        }
        return numbers[high];
    }  
};