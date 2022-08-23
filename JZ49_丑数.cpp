// ��С��(���ȶ���)
// ��ϣ����ȥ��
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {   // n�������ĳ��������
        vector<int> factors = {2, 3, 5};    // ����������
        unordered_set<long> seen;    // �����Ĵ�š��������Ĺ�ϣ����
        priority_queue<long, vector<long>, greater<long>> heap;     // С����
        // Ҳ����С��
        seen.insert(1L);  // ��ϣ�����в���1
        heap.push(1L);    // ���в���1
        int ugly = 0;    // ��ʾ���������
        for (int i=0; i<n; i++) {
            long curr = heap.top();  // ��ǰ�Ѷ���Ԫ�أ���������Сֵ��
            heap.pop();    // �����Ѷ�Ԫ��
            ugly = (int) curr;
            for (int factor: factors) {    // ���α�������������
                long next = curr * factor;   // ���ܵ���һ������
                if (!seen.count(next)) {    // �������û�г��ֹ�
                    seen.insert(next);       // ���������뵽��ϣ������
                    // ��ϣ��������ȥ�أ��Ѷ�������ȡ��ǰ�ĳ�����˳�����У�
                    heap.push(next);
                }
            }

        }
        return ugly;
    }
};


// ��̬�滮��
class Solution {
public:
    int nthUglyNumber(int n) {  // dp[i]�����i����������n��������dp[n]
        vector<int> dp(n+1);    // ����Ϊn+1��vector
        dp[1] = 1;    // ��һ������Ϊ1
        int p2 = 1, p3 = 1, p5 = 1;     // ��������ָ�룬��ʼʱ������ָ���ֵ��Ϊ1
        for (int i=2; i<=n; i++) {
            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);    // �������ߵ���Сֵ��Ϊ��һ������ĳ���
            if (dp[i] == num2) {
                p2++;
            }
            if (dp[i] == num3) {
                p3++;
            }
            if (dp[i] == num5) {
                p5++;
            }
        }
        return dp[n];
    }
};