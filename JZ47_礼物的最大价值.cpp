#include <vector>
using namespace std;

// ��̬�滮dp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();        
        int n = grid[0].size();
        vector<int> dp(n);   // ������һ��һά��dp����, ����Ϊ������
        dp[0] = grid[0][0];
        for (int i=1; i<n; i++)  
            dp[i] = grid[0][i] + dp[i-1];
        for (int i=1; i<m; i++)       // ��
        {
            for (int j=0; j<n; j++) {     // ��
                if (j == 0) 
                    dp[j] = dp[j] + grid[i][j];
                else
                    dp[j] = grid[i][j] + max(dp[j-1],dp[j]);
            }
        }
        return dp[n-1];

    }
};