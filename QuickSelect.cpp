class Solution {
unordered_map<int, int> count_map;
    vector<int> unique;
     void quick_select(int left, int right, int k) {
        if (left == right) 
            return;
        int pivot_index = left + rand()%(right - left + 1);

        pivot_index = partition(left, right, pivot_index);

        if (pivot_index == k)
            return;
        else if (pivot_index < k) 
            quick_select(pivot_index+1, right, k);
        else
            quick_select(left, pivot_index-1, k);
    } 
    int partition(int left, int right, int pivot_index) {
        int pivot_frequency = count_map[unique[pivot_index]];

        swap(unique[pivot_index], unique[right]);
        int store_point = left;

        for (int i=left; i<=right; i++) {
            if (count_map[unique[i]] > pivot_frequency) {
                swap(unique[store_point], unique[i]);
                store_point++;
            }
        }
        swap(unique[store_point], unique[right]);

        return store_point;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int& num: nums) 
            count_map[num] = count_map.count(num)>0?count_map[num]+1:1;

        for (pair<const int, int>& p: count_map)
            unique.push_back(p.first);

        int n = count_map.size();

        quick_select(0, n-1, k);

        return vector<int>(unique.begin(), unique.begin()+k);
    }
};
