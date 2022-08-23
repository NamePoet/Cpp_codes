class Solution {
public:
    bool isMatch(string s, string p) {
        // s是字符串，p是模板字符串
        if (s.empty()  ||  p.empty())
            return false;
        
        return matchCore(s,p);

    bool matchCore(char* s, char* p) {
        if (*s == '\0' && *p == '\0')
            return true;
        if(*s != '\0' && *p == '\0')
            return false;
        if(*(p+1) == '*')
        {
            if(*p == *s || (*p == '.' && *s != '\0'))
            // move on the next state
        return matchCore(s+1, p+2)
            // stay on the current state
            || matchCOre(s+1, p);
            // ignore a'*'
            || matchCore(s, p+2);
            else
                // ignore a '*'
            return matchCore(s, p+2);
        }

        if (*s == *p || (*p=='.' && *s != '\0'))
            return matchCore(s+1, p+1);

        return false;
    }
    }
}; 







/*

class Solution {
public:
    bool isMatch(char* s, char* p) {
        // s是字符串，p是模板字符串
        if (s == nullptr || p == nullptr)
            return false;
        
        return matchCore(s,p);
        }
    bool matchCore(char* s, char* p) {
        if (*s == '\0' && *p == '\0')
            return true;
        if(*s != '\0' && *p == '\0')
            return false;
        if(*(p+1) == '*')
        {
            if(*p == *s || (*p == '.' && *s != '\0'))
            // move on the next state
        return matchCore(s+1, p+2)
            // stay on the current state
            || matchCore(s+1, p)
            // ignore a'*'
            || matchCore(s, p+2);
            else
                // ignore a '*'
            return matchCore(s, p+2);
        }

        if (*s == *p || (*p=='.' && *s != '\0'))
            return matchCore(s+1, p+1);

        return false;
    }
};
*/


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1, n = p.size() + 1;
        // 二维布尔型数组
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        for (int j=2; j<n; j+=2)
            dp[0][j] = dp[0][j-2] && p[j-1] =='*';
        for (int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                 dp[i][j] = p[j-1] == '*' ? 
                dp[i][j-2] || dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'):
                dp[i-1][j-1] && (p[j-1] == '.' || s[i-1] == p[j-1]);
            }
           
        }

    return dp[m-1][n-1];    
    }
    
};

