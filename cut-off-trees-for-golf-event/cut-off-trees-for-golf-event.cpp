class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size(), dir[5] = {-1, 0, 1, 0, -1}; 
        bool seen[m][n]; 
        
        auto fn = [&](pair<int, int>& start, pair<int, int>& end) {
            int ans = 0; 
            memset(seen, false, sizeof(seen)); 
            seen[start.first][start.second] = true; 
            queue<pair<int, int>> q; q.push(start); 
            for (; q.size(); ++ans) 
                for (int sz = q.size(); sz; --sz) {
                    auto [i, j] = q.front(); q.pop(); 
                    if (i == end.first && j == end.second) return ans; 
                    for (int k = 0; k < 4; ++k) {
                        int ii = i + dir[k], jj = j + dir[k+1]; 
                        if (0 <= ii && ii < m && 0 <= jj && jj < n && forest[ii][jj] != 0 && !seen[ii][jj]) {
                            seen[ii][jj] = true; 
                            q.emplace(ii, jj); 
                        }
                    }
                }
            return -1; 
        }; 
        
        vector<tuple<int, int, int>> vals; 
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (forest[i][j] > 1) vals.emplace_back(forest[i][j], i, j); 
        sort(vals.begin(), vals.end()); 
        
        int ans = 0; 
        pair<int, int> start = {0, 0}; 
        for (auto& [v, i, j] : vals) {
            pair<int, int> end = {i, j}; 
            int val = fn(start, end); 
            if (val == -1) return -1; 
            ans += val; 
            start = end; 
        }
        return ans; 
    }
};