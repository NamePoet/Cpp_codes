#include <vector>
using namespace std;

// �ݹ�����㷨 

class Solution {
public:
    // �����Ŀ����ĺ����������Ͳ������̾���дһ��Ƕ�׺���

    bool verifyPostorder(vector<int>& postorder) {
        return verifyOrder(postorder, 0, postorder.size() - 1);
    }

    bool verifyOrder(vector<int>& postorder, int left, int right) {
        if (left >= right) return true;        // ˵���������������С�ڵ���1�������б�ֱ�ӷ���true
        int i;
        for(i = right; i >= left; i--) {
            if (postorder[i] < postorder[right])  break;        // �˴���postorder[right]�Ǹ�����ֵ
        }
        // ���������ҵ���һ�����ӽڵ㣬��λ��Ϊi,�ҵ����������ķֽ���
        for(int j = i; j >= left; j--) {
            if (postorder[j] > postorder[right]) return false;
        }
        // �����ӽ������������Ƿ�С�ڸ���㣬������ǵĻ���˵�����Ǻ������

        return verifyOrder(postorder, left, i) && verifyOrder(postorder, i+1, right - 1);
        // �ٷֱ�������������������б��������Ƿ�����������Ҳ��������������Ķ���
    }


};