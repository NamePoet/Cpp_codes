#include <utility>
#include <vector>
// 1) BFS�ⷨ: O(mn)
class Solution1 {
    // ����x����λ֮��
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
        if(!k)   return 1;      // ���kΪ0�Ļ���ֻ�ܷ���1�����ӣ���(0,0)
        queue<pair<int,int> > Q;   // ����һ�����һϵ�С����ꡱ�Ķ���
        // ���Һ����µķ�������
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        vector<vector<int> > vis(m, vector<int>(n, 0));   // ����һ����άvector�����飩������ֵΪ0
        Q.push(make_pair(0, 0));  // (0,0)���
        vis[0][0] = 1;            // �������߹�
        int ans = 1;
        // ���ν������ߵ����������
        while (!Q.empty()) {
            auto [x, y] = Q.front();      // Ŀǰx, y�ֱ�Ϊ0����0,0������
            Q.pop();
            for (int i=0; i<2; ++i) {
                int tx = dx[i] + x;       // �µĺ����꣬��������չ����������չ
                int ty = dy[i] + y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k)  
                    // ���������Щ������������������Ͳ����
                    continue;
                Q.push(make_pair(tx, ty));   // �����������������
                vis[tx][ty] = 1;           // ����߹�
                ans++;                    // �߹����������+1
            }
        }
        return ans;

    }
};


// 2) ���ƽⷨ��O(mn)  �����ķ���ֻ��Ҫ���»���
class Solution2 {
    int get(int x) {
        int res=0;
        for (; x; x /= 10){
            res += x % 10;
        }
        return res;
    }
public:
    // m ������ n ���� �� k ���ɳ���������
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        vector<vector<int> > vis(m, vector<int>(n, 0));
        int ans = 1;
        vis[0][0] = 1;           // vis��visited�ļ�д������߹�
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 && j == 0) || get(i) + get(j) > k) continue;
                // �߽��ж�
                if (i - 1 >= 0) vis[i][j] |= vis[i-1][j];   // vis[i][j] = vis[i][j] | vis[i-1][j];
                if (j - 1 >= 0) vis[i][j] |= vis[i][j-1];   // vis[i][j] = vis[i][j] | vis[i][j-1];
                ans += vis[i][j];
            }
            // (i,j)����ֻ���(i-1,j)����(i,j-1)���������߹�������ֻҪ��һ�����ӿɴ
            // ��(i,j)������Ӿ��ǿɴ�ģ��������и��ӣ�����������Ƿ�ɴ�Ȼ���ñ���ans
            // ��¼�ɴ�ĸ�����������
        }
        return ans;
    }
};

