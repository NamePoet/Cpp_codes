#include <stack>
using std::stack;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()==0)
            return true;
        
        stack<int> sta;      // 定义一个栈
        int j = 0;


        // 每压入一个元素就进行一次检查
        for(int i=0; i<pushed.size(); i++)
        {
            sta.push(pushed[i]);   // 按次序依次将元素入栈
            while(!sta.empty() && sta.top() == popped[j])     
            //如果当前栈不为空，而且栈顶元素和弹出序列栈顶元素相同，则弹出它
            {
                sta.pop();
                j++;          // 弹出序列索引向后1位
            }
        }

        // 这个双重循环非常漂亮！指利用了一个栈就完成了按要求入栈出栈的操作

        if(sta.empty())
            return true;        // 表明弹出序列可行
        return false;
    }
};