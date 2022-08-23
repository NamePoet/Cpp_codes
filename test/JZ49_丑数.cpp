// 最小堆(优先队列)
// 哈希集合去重
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {   // n代表待求的丑数的序号
        vector<int> factors = {2, 3, 5};    // 公因子序列
        unordered_set<long> seen;    // 创建的存放“丑数”的哈希集合
        priority_queue<long, vector<long>, greater<long>> heap;     // 小顶堆
        // 也称最小堆
        seen.insert(1L);  // 哈希集合中插入1
        heap.push(1L);    // 堆中插入1
        int ugly = 0;    // 表示丑数的序号
        for (int i=0; i<n; i++) {
            long curr = heap.top();  // 当前堆顶的元素（丑数的最小值）
            heap.pop();    // 弹出堆顶元素
            ugly = (int) curr;
            for (int factor: factors) {    // 依次遍历各个公因子
                long next = curr * factor;   // 可能的下一个丑数
                if (!seen.count(next)) {    // 如果该数没有出现过
                    seen.insert(next);       // 将该数插入到哈希集合中
                    // 哈希集合用于去重，堆顶用于提取当前的丑数（顺序排列）
                    heap.push(next);
                }
            }

        }
        return ugly;
    }
};


// 动态规划法
class Solution {
public:
    int nthUglyNumber(int n) {  // dp[i]代表第i个丑数，第n个丑数即dp[n]
        vector<int> dp(n+1);    // 长度为n+1的vector
        dp[1] = 1;    // 第一个丑数为1
        int p2 = 1, p3 = 1, p5 = 1;     // 定义三个指针，初始时，三个指针的值都为1
        for (int i=2; i<=n; i++) {
            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);    // 将这三者的最小值作为下一个按序的丑数
            if (dp[i] == num2) {
                p2++;
            }
            if (dp[i] == num3) {
                p3++;
            }
            if (dp[i] == num5) {
                p5++;
            }
        }
        return dp[n];
    }
};