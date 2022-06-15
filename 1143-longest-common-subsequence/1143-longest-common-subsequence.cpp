class Solution {
public:
    int dp[1002][1002];
    
    int LCS(string& x,string& y,int n,int m){
        if(n==0||m==0)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(x[n-1]==y[m-1])
            return dp[n][m]=1+LCS(x,y,n-1,m-1);
        else
            return dp[n][m]= max(LCS(x,y,n,m-1),LCS(x,y,n-1,m));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n =text1.size();
        int m=text2.size();
        memset(dp,-1,sizeof(dp));
        return LCS(text1,text2,n,m);
    }
};