class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        int toReturn = 0; //minutes
        int numOranges = 0;
        queue<pair<int, int>> rotten;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    rotten.push(make_pair(i,j));
                }
                else if (grid[i][j] == 1) {
                    numOranges++;
                }
            }
        }
        if (numOranges == 0) return 0; //no oranges to make rotten
        pair<int, int> p;
        int size;
        int x, y;
        while (!rotten.empty()) {
            size = rotten.size();
            for (int i = 0; i < size; i++) {
                p = rotten.front();
                rotten.pop();
                x = p.first;
                y = p.second;
                //check if coordinate is valid, then if there is a clean orange
                if (x+1 < m && grid[x+1][y] == 1) {
                    grid[x+1][y] = 2;
                    numOranges--;
                    rotten.push(make_pair(x+1, y));
                }
                if (x-1 >= 0 && grid[x-1][y] == 1) {
                    grid[x-1][y] = 2;
                    numOranges--;
                    rotten.push(make_pair(x-1, y));
                }
                if (y+1 < n && grid[x][y+1] == 1) {
                    grid[x][y+1] = 2;
                    numOranges--;
                    rotten.push(make_pair(x, y+1));
                }
                if (y-1 >= 0 && grid[x][y-1] == 1) {
                    grid[x][y-1] = 2;
                    numOranges--;
                    rotten.push(make_pair(x, y-1));
                }
            }
            toReturn++;
        }
        
        toReturn--; //subtract one minute for last set of oranges that became rotten
        if (numOranges > 0) {
            toReturn = -1;
        }
        return toReturn;
    }
};