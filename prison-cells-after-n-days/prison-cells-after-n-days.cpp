class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int size=n-1;
        vector<int> temp(cells.size(),0);
        vector<int> repeated(cells.size(),0);
        while(n--){
            for(int i=1;i<cells.size()-1;i++){
                if(cells[i-1]==0 && cells[i+1]==0 || cells[i-1]==1 && cells[i+1]==1){
                    temp[i]=1;
                }
                else{
                    temp[i]=0;
                }
            }  
            for(int i=0;i<cells.size();i++){
                if(size==n){
                    repeated[i]=temp[i];
                   
                }
                cells[i]=temp[i];
            }
           
            bool ans=true;
            for(int i=0;i<cells.size();i++){
                if(repeated[i]!=temp[i]){
                    ans=false;
                    break;
                }
            }
            if(ans==true && size!=n) n=n%(size-n);
        }
        return cells;
    }
};