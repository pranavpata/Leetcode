#define ll long long int
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<ll> dp(m);
        for (int i = 0; i < m; i++) {
            dp[i] = points[0][i];
        }
        vector<ll> left(m, 0);
        vector<ll> right(m, 0);
        
        for (int i = 1; i < n; i++) {
            left[0] = dp[0];
            right[m - 1] = dp[m - 1];
            for (int j = 1; j < m; j++) {
                left[j] = max(left[j - 1] - 1, dp[j]);
                right[m - j - 1] = max(right[m - j] - 1, dp[m - j - 1]);
            }
            
            for (int j = 0; j < m; j++) {
                dp[j] = points[i][j] + max(left[j], right[j]);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};