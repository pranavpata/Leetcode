class FindSumPairs {
public:
    
    vector<int> one;
    vector<int> two;
    map<int, int> nums;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        one = nums1;
        two = nums2;
        for (int i = 0; i < two.size(); i++) {
            nums[two[i]]++;
        }
    }
    
    void add(int index, int val) {
        nums[two[index]]--;
        two[index] += val;
        nums[two[index]]++;
    }
    
    int count(int tot) {
        int toReturn = 0;
        for (int i = 0; i < one.size(); i++) {
            toReturn += nums[tot - one[i]];
        }
        return toReturn;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */