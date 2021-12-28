class Solution {
public:
    bool check(string &s1, string &s2) {
        int diff=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i] != s2[i])
            diff++;

            if(diff==2)
                return false;
        }
       return true;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push(beginWord);
        int ans=0;
        
        
        while(!q.empty())
        {
            ans++;
            int s= q.size();
            
            for(int i=0;i<s;i++)
            {
                string temp= q.front();
                q.pop();

                if(temp==endWord)
                return ans;

                for(int i=0;i<wordList.size();i++)
                {
                    if(     wordList[i].length() !=0 && check(wordList[i],temp)==true )
                    {
                    q.push(wordList[i]);
                        wordList[i]= "";
                    }
                }
            }
              
            
        }
        
        return 0;
    }
};