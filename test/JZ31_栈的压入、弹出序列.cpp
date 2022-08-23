#include <stack>
using std::stack;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()==0)
            return true;
        
        stack<int> sta;      // ����һ��ջ
        int j = 0;


        // ÿѹ��һ��Ԫ�ؾͽ���һ�μ��
        for(int i=0; i<pushed.size(); i++)
        {
            sta.push(pushed[i]);   // ���������ν�Ԫ����ջ
            while(!sta.empty() && sta.top() == popped[j])     
            //�����ǰջ��Ϊ�գ�����ջ��Ԫ�غ͵�������ջ��Ԫ����ͬ���򵯳���
            {
                sta.pop();
                j++;          // ���������������1λ
            }
        }

        // ���˫��ѭ���ǳ�Ư����ָ������һ��ջ������˰�Ҫ����ջ��ջ�Ĳ���

        if(sta.empty())
            return true;        // �����������п���
        return false;
    }
};