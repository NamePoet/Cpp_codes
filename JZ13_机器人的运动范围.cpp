#include <utility>
#include <vector>
// 1) BFS解法: O(mn)
class Solution1 {
    // 计算x的数位之和
    int get(int x)
    {
        int sum = 0;
        while(x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
public:
    int movingCount(int m, int n, int k) {
        if(!k)   return 1;      // 如果k为0的话，只能返回1个格子，即(0,0)
        queue<pair<int,int> > Q;   // 创建一个存放一系列“坐标”的队列
        // 向右和向下的方向数组
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        vector<vector<int> > vis(m, vector<int>(n, 0));   // 创建一个二维vector（数组），赋初值为0
        Q.push(make_pair(0, 0));  // (0,0)入队
        vis[0][0] = 1;            // 标记起点走过
        int ans = 1;
        // 依次将可以走到的坐标入队
        while (!Q.empty()) {
            auto [x, y] = Q.front();      // 目前x, y分别为0，（0,0）出队
            Q.pop();
            for (int i=0; i<2; ++i) {
                int tx = dx[i] + x;       // 新的横坐标，先向下拓展，再向右拓展
                int ty = dy[i] + y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k)  
                    // 如果以上这些不满足的条件成立，就不入队
                    continue;
                Q.push(make_pair(tx, ty));   // 满足条件的坐标入队
                vis[tx][ty] = 1;           // 标记走过
                ans++;                    // 走过的坐标个数+1
            }
        }
        return ans;

    }
};


// 2) 递推解法：O(mn)  搜索的方向只需要朝下或朝右
class Solution2 {
    int get(int x) {
        int res=0;
        for (; x; x /= 10){
            res += x % 10;
        }
        return res;
    }
public:
    // m 行数， n 列数 ， k 不可超过的数字
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        vector<vector<int> > vis(m, vector<int>(n, 0));
        int ans = 1;
        vis[0][0] = 1;           // vis是visited的简写，标记走过
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 && j == 0) || get(i) + get(j) > k) continue;
                // 边界判断
                if (i - 1 >= 0) vis[i][j] |= vis[i-1][j];   // vis[i][j] = vis[i][j] | vis[i-1][j];
                if (j - 1 >= 0) vis[i][j] |= vis[i][j-1];   // vis[i][j] = vis[i][j] | vis[i][j-1];
                ans += vis[i][j];
            }
            // (i,j)格子只会从(i-1,j)或者(i,j-1)两个格子走过来，即只要有一个格子可达，
            // 则(i,j)这个格子就是可达的，遍历所有格子，计算出它们是否可达然后用变量ans
            // 记录可达的格子数量即可
        }
        return ans;
    }
};

