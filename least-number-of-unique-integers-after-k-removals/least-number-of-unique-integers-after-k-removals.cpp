class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int n = arr.size();
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        vector<int> heap;
        for(auto x : mp)
            heap.push_back(x.second);
        sort(heap.begin(), heap.end());
        n = heap.size();
        for(int i=0; i<n; i++){
            if(k < heap[i])
                return n-i;
            k -= heap[i];
        }
        return 0;
    }
};