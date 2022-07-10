class Solution {
public:
    static bool comp(string a, string b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int>dp;
        sort(words.begin(), words.end(), comp);
        int ret = 0;
        for(auto x : words){
            for(int i = 0; i < x.size(); i++){
                string temp = x.substr(0, i) + x.substr(i + 1);
                dp[x] = max(dp[x], 1 + dp[temp]);
            }
            ret = max(ret, dp[x]);
        }
        return ret;
    }
};