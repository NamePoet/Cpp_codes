#include <vector>
#include <algorithm>
using namespace std;


// �����㷨����ʱ�临�Ӷ� O(nlogn)  �ռ临�Ӷ� O(log n)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k,0);       // ������k������Ԫ�ص�������ֵ��Ϊ0
        sort(arr.begin(), arr.end());  // ����k��Ԫ�ؽ�������
        // sort() ��һ�ֽ���˲������򡢶�������Ż���Ŀ�������
        for (int i=0; i<k; i++) {
            vec[i] = arr[i];
        }

        return vec;
    }
};



// ���㷨 �����ȶ��С�������ѣ�
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        // ������k������Ԫ�ص�������ֵ��Ϊ0
        if (k == 0)  
            return vec;       // ǰ0����СԪ�أ����ǿ�����
        priority_queue<int> Q;
        for (int i=0; i<k; i++) {
            Q.push(arr[i]);  // �Ƚ�ǰk��Ԫ�ز��������У�
            // ���ӵ�k+1������ʼ�����������ǰ�����������ȴ���ѵĶѶ�����ҪС���ͰѶѶ������������ٲ��뵱ǰ��������
        }
        for (int i=k; i < (int)arr.size(); i++) {
            if (arr[i] < Q.top()) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        // �ⲽ���֮�󣬶��ھ���ǰkС������Ȼ�����vector���ٷ��س�������
        for (int i=0; i<k; i++) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};



// ����˼��
class Solution {
private:
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r-1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i + 1;
    }

    // ��������Ļ���
    int randomized_partition(vector<int>&nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;       // ����[l,r]��Χ�ڵ������
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }

    // �ú������ڻ�������arr��[l, r]���֣�ʹǰkС�������������࣬�ں��������ǵ��ÿ��ŵĻ��ֺ��������軮�ֺ������ص��±���pos
    // ��ʾ�ֽ�ֵpivot�����������е�λ��)
    void randomized_selected(vector<int>&arr, int l, int r, int k) {
        if (l >= r) {
            return;
        }
        int pos = randomized_partition(arr, l, r);
        int num = pos - l + 1;
        if (k == num) {
            return;
        } else if (k < num) {
            randomized_selected(arr, l, pos-1, k);
        } else {
            randomized_selected(arr, pos+1, r, k - num);
        }
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        srand((unsigned)time(NULL));
        randomized_selected(arr, 0, 
        
        (int)arr.size() - 1, k);
        vector<int> vec;
        for (int i=0; i<k; i++) {
            vec.push_back(arr[i]);
        }
        return vec;
    }
};