#include <vector>
using namespace std;

// ���ҳ˻�����
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.size() == 0) 
            return {};
        int length = a.size();

        // L��R�ֱ��ʾ��������ĳ˻��б�, ���Ⱦ�Ϊlength, ��ֵ��Ϊ0
        vector<int> L(length, 0), R(length, 0);

        vector<int> answer(length);

        // L[i]Ϊ����i�������Ԫ�صĳ˻�
        // ��������Ϊ'0'��Ԫ�أ���Ϊ���û��Ԫ�أ�����L[0] = 1;
        L[0] = 1;
        for (int i=1; i<length; i++) 
        {
            L[i] = a[i-1] * L[i-1];           // ʵ��Ҳ�ǵݹ��˼��
        }

        // R[i]Ϊ����i�Ҳ�����Ԫ�صĳ˻�
        // ��������Ϊ'length-1'��Ԫ�ء���Ϊ�Ҳ�û��Ԫ�ء�����R[length-1] = 1
        R[length-1] = 1;
        for (int i=length-2; i>=0; i--) 
        {
            R[i] = a[i+1] * R[i+1];
        }

        // ��������i����a[i]֮������Ԫ�ؾ����������Ԫ�س˻������Ҳ�����Ԫ�س˻�

        for (int i=0; i<length; i++) {
            answer[i] = L[i] * R[i];
        }

        return answer;
    }
};



// �Ż��ռ����������㷨
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.size() == 0) 
            return {};
        int length = a.size();
        vector<int> answer(length);

        // answer[i] ��ʾ���� i �������Ԫ�صĳ˻�
        // ��Ϊ����Ϊ '0' ��Ԫ�����û��Ԫ�أ� ���� answer[0] = 1
        answer[0] = 1;
        for (int i=1; i<length; i++) {
            answer[i] = a[i-1] * answer[i-1];
        }

        // R Ϊ�Ҳ�����Ԫ�صĳ˻�
        // �տ�ʼ�ұ�û��Ԫ�أ����� R = 1
        R = 1;
        for (int i=length-1; i>=0; i--) {
            // �������� i����ߵĳ˻�Ϊ answer[i]���ұߵĳ˻�Ϊ R
            answer[i] = answer[i] * R;
            // R��Ҫ�����ұ����еĳ˻������Լ�����һ�����ʱ��Ҫ����ǰֵ�˵�R��
            R *= a[i];

        }
        return answer;
    }
};