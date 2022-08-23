#include <vector>
#include <algorithm>
using namespace std;


// 排序算法——时间复杂度 O(nlogn)  空间复杂度 O(log n)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k,0);       // 定义了k个整型元素的向量，值均为0
        sort(arr.begin(), arr.end());  // 对这k个元素进行排序
        // sort() 是一种结合了插入排序、堆排序的优化后的快速排序
        for (int i=0; i<k; i++) {
            vec[i] = arr[i];
        }

        return vec;
    }
};



// 堆算法 （优先队列——大根堆）
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        // 定义了k个整型元素的向量，值均为0
        if (k == 0)  
            return vec;       // 前0个最小元素，就是空向量
        priority_queue<int> Q;
        for (int i=0; i<k; i++) {
            Q.push(arr[i]);  // 先将前k个元素插入大根堆中，
            // 随后从第k+1个数开始遍历，如果当前遍历到的数比大根堆的堆顶的数要小，就把堆顶的数弹出，再插入当前遍历的数
        }
        for (int i=k; i < (int)arr.size(); i++) {
            if (arr[i] < Q.top()) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        // 这步完成之后，堆内就是前k小的数，然后插入vector中再返回出来即可
        for (int i=0; i<k; i++) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};



// 快排思想
class Solution {
private:
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r-1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i + 1;
    }

    // 基于随机的划分
    int randomized_partition(vector<int>&nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;       // 产生[l,r]范围内的随机数
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }

    // 该函数用于划分数组arr的[l, r]部分，使前k小的数在数组的左侧，在函数里我们调用快排的划分函数，假设划分函数返回的下标是pos
    // 表示分界值pivot最终在数组中的位置)
    void randomized_selected(vector<int>&arr, int l, int r, int k) {
        if (l >= r) {
            return;
        }
        int pos = randomized_partition(arr, l, r);
        int num = pos - l + 1;
        if (k == num) {
            return;
        } else if (k < num) {
            randomized_selected(arr, l, pos-1, k);
        } else {
            randomized_selected(arr, pos+1, r, k - num);
        }
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        srand((unsigned)time(NULL));
        randomized_selected(arr, 0, 
        
        (int)arr.size() - 1, k);
        vector<int> vec;
        for (int i=0; i<k; i++) {
            vec.push_back(arr[i]);
        }
        return vec;
    }
};