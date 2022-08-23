#include <string>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        // ��ת�����ַ���
        reverse(s.begin(), s.end());  

        int n = s.size();
        int idx = 0;       // ��ʾ�������
        for (int start = 0; start < n; start++) {
            if (s[start] != ' ') {
                // ��һ���հ��ַ�Ȼ��idx�ƶ�����һ�����ʵĿ�ͷλ��
                if (idx != 0) s[idx++] = ' ';

                // ѭ�����������ʵ�ĩβ
                int end = start;
                while (end < n && s[end] != ' ')  s[idx++] = s[end++];       // ��һ��֮��ͣ���˵�һ���ո�

                // ��ת��������
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // ����start��ȥ����һ������
                start = end;
            }
        }              
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};



// ˫�˶��з������ǳ���������õ������ݽṹ�����ԣ�Ҳ�Ǻ÷���
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        // ȥ���ַ�����ͷ�Ŀհ��ַ�
        while (left <= right && s[left] == ' ') ++left;

        // ȥ���ַ���ĩβ�Ŀհ��ַ�
        while (left <= right && s[right] == ' ') --right;

        deque<string> d;
        string word;

        while (left <= right) {
            char c = s[left];
            if (word.size() && c == ' ') {
                // ������ push �����е�ͷ��
                d.push_front(move(word));
                word = "";
            }
            else if (c != ' ') {
                word += c;
            }
            ++left;
        }
        d.push_front(move(word));       //     std::move�ǽ������״̬��������Ȩ��һ������ת�Ƶ���һ������ֻ��ת�ƣ�û���ڴ�İ�Ǩ�����ڴ濽���� 
        
        string ans;
        while (!d.empty()) {
            ans += d.front();
            d.pop_front();
            if (!d.empty()) ans += ' ';
        }
        return ans;
    }
};
