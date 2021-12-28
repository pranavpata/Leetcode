class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) return nums;
        
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        
        auto comp = [&counts](int n1, int n2) { return counts[n1] > counts[n2]; };
        
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        for (pair<int, int> p : counts) {
            heap.push(p.first);
            if (heap.size() > k) heap.pop();
        }
        
        vector<int> top(k);
        for (int i = k-1; i >= 0; i--) {
            top[i] = heap.top();
            heap.pop();
        }
        return top;
    }
};