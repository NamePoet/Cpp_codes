class Solution {
public:
    // C++��ָ����ʵ����ͨ�������������Ϊ����Ԫ�ص��±�������Ԫ��
    vector<int> exchange(vector<int>& nums) {      // ֱ�ӿ��Բ���nums����
    {
        int i = 0, j = nums.size()-1;
        while (i < j)
        {
            while(i < j && (nums[i] & 1) == 1 ) i++;     // �����ܳ�ѭ����ʱ��˵����λ����ż��
            while(i < j && (nums[j] & 1) == 0 ) j--;     // ��ѭ����ʱ��˵����λ��������
            swap(nums[i], nums[j]);  
        }

        return nums;
    }
    }
};