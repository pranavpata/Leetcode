class Solution {
public:
    int numTrees(int n) {
        int dp[30] = {0};
        dp[0] = dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            int result = 0;
            for(int j=1;j<=i;j++)
            {
                int left = dp[j-1];
                int right = dp[i-j];
                result += left * right;
            }
            dp[i] = result;
        }
        return dp[n];
    }
};