class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) return 0;
	    
        priority_queue<int> maxHeap; //smallest 4 numbers
        priority_queue<int, vector<int>, greater<int>> minHeap; //largest 4 numbers
        
        for(int num:nums) {
            if (maxHeap.size() < 4) {
                maxHeap.push(num);
                minHeap.push(num);
            }
            else {
                if (num > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(num);
                }
                if (num < maxHeap.top()) {
                    maxHeap.pop();
                    maxHeap.push(num);
                }
            }
        }
        
        vector<int> small;
        for (int i = 0; i < 4; i++) {
            small.push_back(maxHeap.top());
            maxHeap.pop();
        }
        
        int result = INT_MAX;
        
        int large;
        for (int i = 0; i < 4; i++) {
            large = minHeap.top();
            minHeap.pop();
            result = min(result, large - small[4 - i - 1]);
        }
        
        return result;
    }
};