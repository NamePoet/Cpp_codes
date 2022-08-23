#include <unordered_map>
using namespace std;

// ��ϣ��洢Ƶ��
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<int, int> frequency;      // ��ϣ�������ʽ����������ƣ�Ҳ��a[]��
        for (char ch: s) {
            ++frequency[ch];
        }
        // ��һ�α����Ǵ��������ϣ��,��Ϊfrequency
        for (int i=0; i < s.size(); i++) {
            // ����ԭ�ַ������������ֻ����һ�ε��ַ�
            if (frequency[s[i]] == 1) {
                return s[i];
            }
        }
        // ���ԭ�ַ�����û��ֻ����һ�ε��ַ����ͷ���һ���ո�
        return ' ';
    }
};



// ��ϣ��洢����
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> position;
        int n = s.size();
        for (int i=0; i<n; i++) {
            if (position.count(s[i])) {
                position[s[i]] = -1;      // ������ַ����ֶ�Σ����Ϊ-1
            }
            else
            {
                position[s[i]] = i;       // ���ֻ����һ�Σ��ͼ�¼�״γ��ֵ�����
            }
        }
        int first = n;
        // ���������ϣӳ��
        for (auto [_,pos]:position) {
            if (pos != -1 && pos < first) {
                first = pos;
            }
        }
        return first == n?' ' : s[first];
    }
};