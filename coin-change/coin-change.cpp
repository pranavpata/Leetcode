class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        
        sort(coins.begin(), coins.end());
        if (coins[0] > amount) return -1;
        
        vector<int> dp(amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            dp[i] = INT_MAX;
            for(int j = 0; j < coins.size(); j++){
                if(coins[j] <= i){
                    int ans = dp[i - coins[j]];
                    if(ans != -1){
                         dp[i] = min(ans + 1, dp[i]);
                    }
                   
                }
            }
            if(dp[i] == INT_MAX){
                dp[i] = -1;
            }
        }
        
        return dp[amount];
    }
};