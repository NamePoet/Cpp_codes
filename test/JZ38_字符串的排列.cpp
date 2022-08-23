#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 回溯算法
class Solution {

public:
    vector<string> rec;         // 存放所有经排列过的字符串的vector
    vector<int> vis;

    void backtrack(const string&s, int i, int n, string& perm) {
        if (i == n) {
            rec.push_back(perm);
            return;
        }
        for (int j = 0; j < n; j++) {
            // 保证在填每一个空位的时候重复字符只会被填入一次。
            if (vis[j] || (j > 0 && !vis[j-1] && s[j-1] == s[j]))
                continue;
            vis[j] = true;
            perm.push_back(s[j]);
            backtrack(s, i+1, n, perm);
            perm.pop_back();
            vis[j] = false;
        }
    }

    vector<string> permutation(string s) {
        int n = s.size();
        vis.resize(n);        // 标记是否到过的数组的大小为字符串的长度
        // 对字符串排序，保证相同的字符都相邻
        sort(s.begin(), s.end());
        // perm是s的一个排列
        string perm;
        backtrack(s, 0, n, perm);
        return rec;
    }
};