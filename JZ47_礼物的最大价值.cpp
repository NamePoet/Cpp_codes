#include <vector>
using namespace std;

// 动态规划dp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();        
        int n = grid[0].size();
        vector<int> dp(n);   // 创建了一个一维的dp数组, 长度为其列数
        dp[0] = grid[0][0];
        for (int i=1; i<n; i++)  
            dp[i] = grid[0][i] + dp[i-1];
        for (int i=1; i<m; i++)       // 行
        {
            for (int j=0; j<n; j++) {     // 列
                if (j == 0) 
                    dp[j] = dp[j] + grid[i][j];
                else
                    dp[j] = grid[i][j] + max(dp[j-1],dp[j]);
            }
        }
        return dp[n-1];

    }
};