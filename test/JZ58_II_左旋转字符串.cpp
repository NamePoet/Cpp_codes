#include <string>
using namespace std;
// ����ת�ַ���
// ����Ҫ���� abcdefg   ->     cdefgba
class Solution {
public:
    int reverse_string(string& s, int start, int end) {
        for (int i = start; i <= (start + end) / 2; i++) {       // �м䶨�彻����һ���λ���������һ���ֻ�������
            char temp = s[i];
            s[i] = s[start + end - i];
            s[start + end -i] = temp;
        }
        return 0;
    }
    string reverseLeftWords(string s, int n) {
        int length = s.length();

        reverse_string(s, 0, length-1);             // ��һ�����gfedcba
        reverse_string(s, 0, length-n-1);           // ��һ�����cdefgba
        reverse_string(s, length-n, length-1);      // ��һ�����cdefgab

        return s;
    }
};