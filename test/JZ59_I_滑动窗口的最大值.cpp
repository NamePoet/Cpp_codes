#include <vcruntime.h>
#include <vector>
#include <queue>
using namespace std;

// 运用双端队列deque --- 何海涛想法

// Leetcode 1 优先队列（大根堆）
// 需要判断堆顶元素和滑动窗口的位置关系
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue <pair<int, int>> q;        // 二元组pair：作用是将2个数据合成一组数据
        for (int i = 0; i < k; i++) {
            q.emplace(nums[i], i);                          // 用法类似与insert函数，为C++11特性
            // 插入一个“数与索引”的pair数对
        }
        vector<int> ans = {q.top().first};     // 最大堆的堆顶的值（当前三个数中的最大值）
        for (int i=k; i<n; i++) {
            q.emplace(nums[i], i);
            while (q.top().second <= i-k) {            // 当一个数字的下标与当前处理的数字的下标之差大于或者等于滑动窗口的大小时，这个数字已经从窗口中滑出，可以从队列中删除了
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

// 单调队列算法     双端队列deque（可以同时弹出队首和队尾的元素）
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         int n = nums.size();
         deque<int> q;
         for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
         }

         vector<int> ans = {nums[q.front()]};
         for (int i=k; i<n; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
         q.push_back(i);
         while (q.front() <= i-k) {
            q.pop_front();
         }
         // 当一个数字的下标与当前处理的数字的下标之差大于或者等于滑动窗口的大小时，
         // 这个数字已经从窗口中滑出，可以从队列中删除了
         ans.push_back(nums[q.front()]);
    }
        return ans;
    }
};