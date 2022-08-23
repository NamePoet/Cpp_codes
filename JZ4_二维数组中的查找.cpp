class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        /*判断数组不为空*/

        /****************/
        // matrix.size()表示行    matrix[0].size()表示列
        if (matrix.size()==0 || matrix[0].size()==0) 
            return false;
        
        int row = 0;                    // 当前行
        int col = matrix[0].size()-1;   // 当前列

        while (row < matrix.size() && col >=0) { // 从二维数组(矩阵)的右上角开始遍历
            // 获取当前元素
            int num = matrix[row][col];
            if(num == target) {
                return true;
            } else if(num > target)
            {
                col --;
            } else{
                row ++;
            }

        }
        return false;
    }
};