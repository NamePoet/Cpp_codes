// �ٷ����
class Solution {
public:
              // �˴�����Ϊ��ά����, check��������������.  i��j���ڴ����к��У�k���ڴ����ַ������������,k��ʼ��ֵΪ0
    bool check(vector<vector<char>>&board, vector<vector<int>>&visited, int i, int j, string&s, int k) {
        if(board[i][j] != s[k]) {
            return false;        // �жϵ�ǰѰ�ҵľ����е��������Ƿ��������ַ�����
        } else if(k == s.length()-1) {
            return true;         // �����ǰ�Ѿ��ۼ��жϵĽ�������������ַ����ĳ��ȣ���֤����һ�����ַ��������ھ�����
        }
        visited[i][j] = true;    // ����������Ѿ��߹��ˣ������ﴫ�������ã�����ֱ���޸�
        vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
        bool result = false;
        //"�����pair����������ö��..."   ˳���������Ľ�㣨���꣩
        for(const auto& dir:directions) {
            int newi = i+dir.first, newj = j+dir.second;
            if(newi >=0 && newi<board.size() && newj>=0 && newj < board[0].size()) {
                if(!visited[newi][newj]) {    // ��������ߵ���һ�½�㻹û�б����ʹ�
                    bool flag = check(board, visited, newi, newj, s, k+1);     // �����ǵݹ鷽��������
                    if(flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;   // �˴α�������գ���Ϊ��ֵ���Ա���һ���ܽ��������ı�������
        return result;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols));     // ��vector������Ķ�ά��������
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

// �Ż���1
/*--------------------------------------------�Ľ���----------------------------------------------------*/
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
	 	bool ans(false);  //  ���˸���������
	 	for (int z(0); z < 4; z++) {
	 		int x = i + xy[z][0], y = j + xy[z][1];
	 		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && b[x][y] && board[x][y] == word[index] &&
	         BSF_back(board, word, xy, x, y, index + 1, b)) {
	 			ans = true; // �������ڴ����������Բ�����return
				break;
	 		}
	 	}
	 	b[i][j] = true;  // �ڻָ� b �Ŀ�ʼ״̬����return���������ܴﵽ����Ч����bҲ���Դ������ã���󽵵͸��Ӷ�
	 	return ans;
	}








