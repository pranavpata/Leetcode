class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), step = 0;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<pair<int, int>> arr;
        
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (grid[r][c] == '#')
                    arr.push_back(make_pair(r, c));
        
        while (!arr.empty()) {
            vector<pair<int, int>> nxt_arr;
            step++;
            for (auto & [r, c]: arr) {
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dirs[i][0], nc = c + dirs[i][1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if (grid[nr][nc] == '*') {
                            return step;
                        } else if (grid[nr][nc] == 'O') {
                            grid[nr][nc] = 'X'; // mark as visited
                            nxt_arr.push_back(make_pair(nr, nc));
                        }
                    }
                }
            }
            arr = nxt_arr;
        }

        return -1;
    }
};