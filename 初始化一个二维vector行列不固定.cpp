#include <iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>> matrix;//�У��������̶�
    cout << "please input rows of matrix: " << endl;
    int rows;
    cin >> rows;
    matrix.resize(rows);
    int col;
    vector<int> temp;
    for (int i = 0; i < rows; i++) {
        cout << "please input the cols of " << i << "th row" << endl;
        cin >> col;//ȷ����i�е�����
        cout << i << "th row has " << col << " cols," << "please input these" << endl;
        for (int j = 0; j < col; j++){
            int data;
            cin >> data;
            temp.push_back(data);
        }
        matrix[i] = temp;        // ֱ����ĳһ�в���һ��������������ֱ�ӽ����鸳����
        temp.clear();
    }

    cout << "output matrix:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {      // ��һ���������������Ĳ�ȷ������i�й�
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
 