#include <vcruntime.h>
#include <vector>
using std::vector;


class Solution {

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows <=0 || cols <=0)   return result;

        int start = 0;
        

        while(rows > start * 2 && cols > start * 2)
        {
            int endX = matrix[0].size() - 1 - start;  // 横坐标和列相关(终止列号)
            int endY = matrix.size() - 1 - start;     // 纵坐标和行相关(终止行号)

            // 从左到右打印一行(行不变，列在变), 这一行是至少要打的！（因为可能矩阵只有一维）
            for (int i = start; i <= endX; i++)
            {
                result.push_back(matrix[start][i]);
            }

            // 从上到下打印一列(列不变，行在变)
            if (start < endY)
            {
                for(int i = start + 1; i <= endY; i++)  // 注意这里起始点要+1，因为上一行的这一列的第一个元素已经被打印过了
                {
                    result.push_back(matrix[i][endX]);
                }
            }
            // 从右到左打印一行
            if (start < endX && start < endY)      // 要求终止行号大于起始行号，终止列号大于起始列号
            {
                for(int i = endX-1; i>=start; i--)
                {
                    result.push_back(matrix[endY][i]);
                }
            }
            // 从下到上打印一列
            if (start < endX && start < endY - 1)   // 终止行号比起始行号至少大2，终止列号大于起始列号
            {
                for(int i = endY - 1; i >= start+1; i--)
                {
                    result.push_back(matrix[i][start]);
                }
            }
            
            ++start;
        }
        return result;
    }
};  