// 官方题解
class Solution {
public:
              // 此处参数为二维数组, check函数有六个参数.  i、j用于处理行和列，k用于处理字符串的索引序号,k初始传值为0
    bool check(vector<vector<char>>&board, vector<vector<int>>&visited, int i, int j, string&s, int k) {
        if(board[i][j] != s[k]) {
            return false;        // 判断当前寻找的矩阵中的这个结点是否在所给字符串中
        } else if(k == s.length()-1) {
            return true;         // 如果当前已经累计判断的结点数等于所给字符串的长度，就证明这一连续字符串存在于矩阵中
        }
        visited[i][j] = true;    // 标记这个结点已经走过了，它这里传的是引用，可以直接修改
        vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
        bool result = false;
        //"这里的pair让我想起了枚举..."   顺序遍历这里的结点（坐标）
        for(const auto& dir:directions) {
            int newi = i+dir.first, newj = j+dir.second;
            if(newi >=0 && newi<board.size() && newj>=0 && newj < board[0].size()) {
                if(!visited[newi][newj]) {    // 如果往下走的这一新结点还没有被访问过
                    bool flag = check(board, visited, newi, newj, s, k+1);     // 这里是递归方法来回溯
                    if(flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;   // 此次遍历后清空，置为初值，以便下一轮能进行完整的遍历流程
        return result;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols));     // 用vector来定义的二维整型数组
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if(flag) {
                    return true;
                }
            }
        } 
        return false;
    }
};

// 优化版1
/*--------------------------------------------改进版----------------------------------------------------*/
    bool exist(vector<vector<char>>& board, string& word) {   
	 	vector<vector<bool>> b(board.size(), vector<bool>(board[0].size(), true));
	 	vector<vector<int>> xy({ {1,0},{0,-1},{-1,0},{0,1} });
	 	int index(1);
	 	for (int i(0); i < board.size(); i++)
	 		for (int j(0); j < board[0].size(); j++)
	 			if (board[i][j] == word[0] && BSF_back(board, word, xy, i, j, index, b))
	 				return true;
	 	return false;
	 }
	 bool BSF_back(vector<vector<char>>& board, string& word, vector<vector<int>>& xy, int i, int j, int index, vector<vector<bool>>& b) {
	 	if (index >= word.size()) return true;
	 	b[i][j] = false;
	 	bool ans(false);  //  加了个布尔变量
	 	for (int z(0); z < 4; z++) {
	 		int x = i + xy[z][0], y = j + xy[z][1];
	 		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && b[x][y] && board[x][y] == word[index] &&
	         BSF_back(board, word, xy, x, y, index + 1, b)) {
	 			ans = true; // 变量用于储存结果，可以不马上return
				break;
	 		}
	 	}
	 	b[i][j] = true;  // 在恢复 b 的开始状态后，再return，这样就能达到回溯效果，b也可以传入引用，大大降低复杂度
	 	return ans;
	}








