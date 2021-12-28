class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(auto c:s){
            if((c>='a' and c<='z') or (c>='A' and c<='Z') or (c>='0' and c<='9')){
                if(c>='a' and c<='z')c=toupper(c);
                
                ans+=c;
            }
        }
        //        cout<<ans<<endl;
        int n=ans.length();
        for(int i=0;i<n/2;i++){
            if(ans[i]!=ans[n-i-1])
                return false;
        }
        return true;
    }
};