class Solution {
public:
    string replaceSpace(string s) {
        int originalLength = s.size();
        if(s.size()==0)
            return s;
        int numberOfBlank = 0;
        for(char c:s)         // C++11特性。简化遍历的方式
        {
            if(c == ' ')
                numberOfBlank++;
        }
        // 接着修改字符串长度
        s.resize(originalLength+ 2*numberOfBlank);
        for(int i=originalLength-1, j=s.size()-1; i<j; i--, j--)   // 用索引来代替指针的作用
        {
            if(s[i] == ' ')
            {
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j-=2;
            }   
            else
            {
                s[j] = s[i];
            }
            
        }
        return s;
    }
};


   
   