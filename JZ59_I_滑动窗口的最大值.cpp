#include <vcruntime.h>
#include <vector>
#include <queue>
using namespace std;

// ����˫�˶���deque --- �κ����뷨

// Leetcode 1 ���ȶ��У�����ѣ�
// ��Ҫ�ж϶Ѷ�Ԫ�غͻ������ڵ�λ�ù�ϵ
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue <pair<int, int>> q;        // ��Ԫ��pair�������ǽ�2�����ݺϳ�һ������
        for (int i = 0; i < k; i++) {
            q.emplace(nums[i], i);                          // �÷�������insert������ΪC++11����
            // ����һ����������������pair����
        }
        vector<int> ans = {q.top().first};     // ���ѵĶѶ���ֵ����ǰ�������е����ֵ��
        for (int i=k; i<n; i++) {
            q.emplace(nums[i], i);
            while (q.top().second <= i-k) {            // ��һ�����ֵ��±��뵱ǰ��������ֵ��±�֮����ڻ��ߵ��ڻ������ڵĴ�Сʱ����������Ѿ��Ӵ����л��������ԴӶ�����ɾ����
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

// ���������㷨     ˫�˶���deque������ͬʱ�������׺Ͷ�β��Ԫ�أ�
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
         // ��һ�����ֵ��±��뵱ǰ��������ֵ��±�֮����ڻ��ߵ��ڻ������ڵĴ�Сʱ��
         // ��������Ѿ��Ӵ����л��������ԴӶ�����ɾ����
         ans.push_back(nums[q.front()]);
    }
        return ans;
    }
};