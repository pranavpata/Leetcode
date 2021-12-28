class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> lastIndex(26,0);
        for(int i=0;i<s.length();i++)
        {
            lastIndex[s[i]-'a']=i;
        }
        int maxi=-1;
        int prev=0;
        for(int i=0;i<s.length();i++)
        {
            maxi=max(maxi,lastIndex[s[i]-'a']);
            if(i==maxi)
            {
                ans.push_back(i-prev+1);
                prev=i+1;
            }
        }
        return ans;
    }
};