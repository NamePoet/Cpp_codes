#include <string>
using namespace std;
// 左旋转字符串
// 例如要交换 abcdefg   ->     cdefgba
class Solution {
public:
    int reverse_string(string& s, int start, int end) {
        for (int i = start; i <= (start + end) / 2; i++) {       // 中间定义交换到一半的位置是以免后一半又换回来了
            char temp = s[i];
            s[i] = s[start + end - i];
            s[start + end -i] = temp;
        }
        return 0;
    }
    string reverseLeftWords(string s, int n) {
        int length = s.length();

        reverse_string(s, 0, length-1);             // 这一步变成gfedcba
        reverse_string(s, 0, length-n-1);           // 这一步变成cdefgba
        reverse_string(s, length-n, length-1);      // 这一步变成cdefgab

        return s;
    }
};