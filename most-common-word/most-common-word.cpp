class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        unordered_map<string,int>m;
        int frequency = 0;
        string s = "";
        for(int i=0;i<p.size();i++){
            if((p[i]>='a' and p[i]<='z') or (p[i]>='A' and p[i]<='Z')){
                s+=tolower(p[i]);
            }
            else{
                if(s.length()>0){
                    m[s]++,s="";
                }
            }
        }
        m[s]++;
        for(auto i:banned)  m[i]=0;
        for(auto i:m){
            if(frequency<=i.second){
                s=i.first,frequency = i.second;
            }
        }
        return s;
    }
};