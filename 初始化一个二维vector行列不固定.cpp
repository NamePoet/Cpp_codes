#include <iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>> matrix;//行，列数不固定
    cout << "please input rows of matrix: " << endl;
    int rows;
    cin >> rows;
    matrix.resize(rows);
    int col;
    vector<int> temp;
    for (int i = 0; i < rows; i++) {
        cout << "please input the cols of " << i << "th row" << endl;
        cin >> col;//确定第i行的列数
        cout << i << "th row has " << col << " cols," << "please input these" << endl;
        for (int j = 0; j < col; j++){
            int data;
            cin >> data;
            temp.push_back(data);
        }
        matrix[i] = temp;        // 直接往某一行插入一个向量，类似于直接将数组赋过来
        temp.clear();
    }

    cout << "output matrix:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {      // 这一步就体现了列数的不确定，与i有关
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
 