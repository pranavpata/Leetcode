class Solution {
public:
    int dp(vector<vector<int>>& grid,vector<vector<vector<int>>>&v,int r1,int c1,int r2,int n){
        int c2=r1+c1-r2;
        if(r1>=n || r2>=n ||c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)return INT_MIN;
        if(v[r1][c1][r2]!=-1)return v[r1][c1][r2];
        if(r1==n-1 && c1==n-1)return grid[r1][c1];
        int x=dp(grid,v,r1+1,c1,r2,n);
        int y=dp(grid,v,r1,c1+1,r2,n);
        int z=dp(grid,v,r1+1,c1,r2+1,n);
        int w=dp(grid,v,r1,c1+1,r2+1,n);
        if(r1==r2 && c1==c2){
            return v[r1][c1][r2]=grid[r1][c1]+max(max(x,y),max(w,z));
        }
        return v[r1][c1][r2]=grid[r1][c1]+grid[r2][c2]+max(max(x,y),max(w,z));
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>>v(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int r1=0,c1=0,r2=0;
        return max(0,dp(grid,v,r1,c1,r2,n));
    }
};