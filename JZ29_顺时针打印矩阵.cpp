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
            int endX = matrix[0].size() - 1 - start;  // ������������(��ֹ�к�)
            int endY = matrix.size() - 1 - start;     // ������������(��ֹ�к�)

            // �����Ҵ�ӡһ��(�в��䣬���ڱ�), ��һ��������Ҫ��ģ�����Ϊ���ܾ���ֻ��һά��
            for (int i = start; i <= endX; i++)
            {
                result.push_back(matrix[start][i]);
            }

            // ���ϵ��´�ӡһ��(�в��䣬���ڱ�)
            if (start < endY)
            {
                for(int i = start + 1; i <= endY; i++)  // ע��������ʼ��Ҫ+1����Ϊ��һ�е���һ�еĵ�һ��Ԫ���Ѿ�����ӡ����
                {
                    result.push_back(matrix[i][endX]);
                }
            }
            // ���ҵ����ӡһ��
            if (start < endX && start < endY)      // Ҫ����ֹ�кŴ�����ʼ�кţ���ֹ�кŴ�����ʼ�к�
            {
                for(int i = endX-1; i>=start; i--)
                {
                    result.push_back(matrix[endY][i]);
                }
            }
            // ���µ��ϴ�ӡһ��
            if (start < endX && start < endY - 1)   // ��ֹ�кű���ʼ�к����ٴ�2����ֹ�кŴ�����ʼ�к�
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