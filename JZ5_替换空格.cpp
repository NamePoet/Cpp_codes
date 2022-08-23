class Solution {
public:
    string replaceSpace(string s) {
        int originalLength = s.size();
        if(s.size()==0)
            return s;
        int numberOfBlank = 0;
        for(char c:s)         // C++11���ԡ��򻯱����ķ�ʽ
        {
            if(c == ' ')
                numberOfBlank++;
        }
        // �����޸��ַ�������
        s.resize(originalLength+ 2*numberOfBlank);
        for(int i=originalLength-1, j=s.size()-1; i<j; i--, j--)   // ������������ָ�������
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


   
   