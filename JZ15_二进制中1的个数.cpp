#include <float.h>
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        unsigned int flag = 1;
        while (flag)
        {
            if (n & flag)
                count++;
            
            flag = flag << 1;     // ÿ������һλ�Ǳ�ʾ��������Ϊԭ��������
        }
        return count;
    }
};




class Solution {
// ��һ��������ȥ1���ٺ�ԭ�����������㣬��Ѹ��������ұߵ�1���0����ôһ�������Ķ����Ʊ�ʾ��
// �ж��ٸ�1���Ϳ��Խ��ж��ٴ������Ĳ�����
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while (n) {
            ++count;
            n = (n-1)&n;
        }

        return count;
    }
};