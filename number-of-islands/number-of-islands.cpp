class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int toReturn = 0;
        queue<pair<int,int>> points;
        int x, y;
        pair<int, int> current;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    points.push(make_pair(i,j));
                    grid[i][j] = '2'; //visited
                    toReturn++;
                    while (!points.empty()) {
                        current = points.front();
                        points.pop();
                        x = current.first;
                        y = current.second;
                        if (x-1 >= 0 && grid[x-1][y] == '1') {
                            points.push(make_pair(x-1,y));
                            grid[x-1][y] = '2';
                        } 
                        if (x+1 < grid.size() && grid[x+1][y] == '1') {
                            points.push(make_pair(x+1,y));
                            grid[x+1][y] = '2';
                        } 
                        if (y-1 >= 0 && grid[x][y-1] == '1') {
                            points.push(make_pair(x,y-1));
                            grid[x][y-1] = '2';
                        } 
                        if (y+1 < grid[0].size() && grid[x][y+1] == '1') {
                            points.push(make_pair(x,y+1));
                            grid[x][y+1] = '2';
                        } 
                    }
                }
            }
        }
        return toReturn;
    }
};