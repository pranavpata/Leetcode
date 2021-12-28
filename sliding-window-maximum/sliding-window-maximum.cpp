class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        vector<int> ans;
        
        int low, high;
        
        for(int i=0; i<nums.size(); i++) {
            
            if (dq.empty()) {
                dq.push_back({nums[i],i});
            }
            else {
                
                // 1-- first element in range ?
                low = i+1-k;
                high = i;
                    
                pair<int,int> first = dq.front();
                if (first.second > high || first.second < low) {
                    dq.pop_front();
                }
                
                // 2-- check sorting order
                while(dq.empty() == false && dq.back().first < nums[i]) {
                    dq.pop_back();
                }
                
                // 3-- insert the current element
                dq.push_back({nums[i],i});
            }
            
            if (i+1-k >= 0 && !dq.empty()) {
                ans.push_back(dq.front().first);
            }
        }
        
        return ans;
    }
};