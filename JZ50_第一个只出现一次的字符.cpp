#include <unordered_map>
using namespace std;

// 哈希表存储频数
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<int, int> frequency;      // 哈希表操作方式和数组很类似，也是a[]型
        for (char ch: s) {
            ++frequency[ch];
        }
        // 第一次遍历是创建这个哈希表,名为frequency
        for (int i=0; i < s.size(); i++) {
            // 遍历原字符串，查找这个只出现一次的字符
            if (frequency[s[i]] == 1) {
                return s[i];
            }
        }
        // 如果原字符串中没有只出现一次的字符，就返回一个空格
        return ' ';
    }
};



// 哈希表存储索引
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> position;
        int n = s.size();
        for (int i=0; i<n; i++) {
            if (position.count(s[i])) {
                position[s[i]] = -1;      // 如果该字符出现多次，则记为-1
            }
            else
            {
                position[s[i]] = i;       // 如果只出现一次，就记录首次出现的索引
            }
        }
        int first = n;
        // 遍历这个哈希映射
        for (auto [_,pos]:position) {
            if (pos != -1 && pos < first) {
                first = pos;
            }
        }
        return first == n?' ' : s[first];
    }
};