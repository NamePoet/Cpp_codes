#include <string>
#include <vector>
using namespace std;


class Solution {
private:
     void quicksort(vector<string>&strs, int l, int r) {
        if(l >= r) return;
        int i = l, j = r;
        while(i < j) {
            while(strs[j] + strs[l] >= strs[l] + strs[j] && i < j) j--;
            while(strs[i] + strs[l] <= strs[l] + strs[i] && i < j) i++;
            swap(strs[i], strs[j]);
        }
        swap(strs[i], strs[l]);
        quicksort(strs, l, i-1);
        quicksort(strs, i+1, r);
     }
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (int i=0; i<nums.size(); i++)
            strs.push_back(to_string(nums[i]));    // ����Ŀ������������ת���ַ�������strs
        quicksort(strs, 0, strs.size()-1);      // �Զ�����һ��������������������
        string res;
        for (string s:strs)      // ��ǿforѭ��
            res.append(s);
        return res;
    }
};