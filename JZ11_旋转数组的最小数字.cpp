// ���ֲ��ҷ�
// ������ָ��ֱ�ָ������ĵ�һ��Ԫ�غ����һ��Ԫ�أ�������ת���򣬵�һ��Ԫ��Ӧ���Ǵ��ڻ���
// �������һ��Ԫ�ص�

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0;
        int high = numbers.size() - 1;
        // ����������ָ�롱��ʵ���������±�
        while (low < high) {
            int mid = (low + high) / 2;
            if(numbers[mid] > numbers[high])
            {
                low = mid+1;
            } else if(numbers[mid] < numbers[high]) {
                high = mid;
            }
            else{
                high -=1;             // �ⲽ�ܹؼ������ظ�����ʱ����λ�����м��Ǹ���
            }         
        }
        return numbers[high];
    }  
};