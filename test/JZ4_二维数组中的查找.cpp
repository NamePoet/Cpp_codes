class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        /*�ж����鲻Ϊ��*/

        /****************/
        // matrix.size()��ʾ��    matrix[0].size()��ʾ��
        if (matrix.size()==0 || matrix[0].size()==0) 
            return false;
        
        int row = 0;                    // ��ǰ��
        int col = matrix[0].size()-1;   // ��ǰ��

        while (row < matrix.size() && col >=0) { // �Ӷ�ά����(����)�����Ͻǿ�ʼ����
            // ��ȡ��ǰԪ��
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