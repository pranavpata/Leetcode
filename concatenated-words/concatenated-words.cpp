class Solution {
private:
    bool dfs(string &word,int start,unordered_set<string>& st,vector<int>& dp)
    {
        if(start==word.size())
            return 1;
        
        if(dp[start]!=-1)
            return dp[start];
        
        string s;
        for(int i=start;i<word.size();++i)
        {
            s+=word[i];
            if(st.find(s)!=st.end() && dfs(word,i+1,st,dp))
                return dp[start]=1;
        }
        return dp[start]=0;
    }
    
    
    
    bool check(string &word,unordered_set<string>& st)
    {
        int n=word.size();
        vector<int>dp(n+1,-1);
        st.erase(word);   // We need to delete that word that we are searching for from our set
        bool res=dfs(word,0,st,dp);
        st.insert(word);          //Then again insert that word 
        return res;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>ans;
        unordered_set<string>st(words.begin(),words.end());
        for(auto &word:words)
        {
            if(word.size()<=1)
                continue;
            if(check(word,st))
                ans.push_back(word);
        }
        
        return ans;
    }
};