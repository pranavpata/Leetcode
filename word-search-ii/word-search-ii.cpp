class Node{
    public:
    Node* links[26];
    bool end;
    string word;
    Node(){
        this->word="WTF";
        this->end=false;
        for(int i=0;i<26;i++) this->links[i]=NULL;
    }
    void put(char ch,Node* node){
        this->links[ch-'a']=node;
    }
    Node* get(char ch){
        return this->links[ch-'a'];
    }
    bool containsKey(char ch){
        return this->links[ch-'a']!=NULL;
    }
};

class Solution {
public:
    vector<string>ans;
    
    void solve(int x,int y,int n,int m,vector<vector<char>>&board,Node* node){
        int index=board[x][y]-'a';
        if(board[x][y]=='$'||node->links[index]==NULL) return ;
        node=node->links[index];
        if(node->end==true){
            ans.push_back(node->word);
            node->end=false;
        } 
        char ch=board[x][y];
        board[x][y]='$';
        if(x>0) solve(x-1,y,n,m,board,node);
        if(y>0) solve(x,y-1,n,m,board,node);
        if(x<n-1) solve(x+1,y,n,m,board,node);
        if(y<m-1) solve(x,y+1,n,m,board,node);
        board[x][y]=ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size();
        int m=board[0].size();
        Node* root=new Node();
        for(int i=0;i<words.size();i++){
            Node* node=root;
            string str=words[i];
            for(int j=0;j<str.length();j++){
                if(node->links[str[j]-'a']==NULL){
                    node->put(str[j],new Node());
                }
                node=node->get(str[j]);
            }
            node->word=words[i];
            node->end=true;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(i,j,n,m,board,root);
            }
        }
        return ans;
    }
};