class Solution {
private:
    static bool compareInterval(int a, int b)
    {
        return abs(a) < abs(b);
    }
public:
    bool canReorderDoubled(vector<int>& arr) {
        if (arr.size() == 0) return true;
        
        map<int, int> mp;
        for (int num:arr) {
            mp[num]++;
        }
        
        sort(arr.begin(), arr.end(), compareInterval);
             
        for (int num:arr) {
            if (mp[num] == 0) continue;
            
            if (mp.find(2 * num) == mp.end()) {
                return false;
            }
            
            if (mp.find(2 * num) != mp.end() && mp[2 * num] == 0) {
                return false;
            }
            
            mp[num]--;
            mp[2 * num]--;
        }
        return true;
    }
};