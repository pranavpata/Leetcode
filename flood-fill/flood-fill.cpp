class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int color, int val) {
        image[x][y] = color; //visited[x][y] = true;
        if (x+1 < image.size() && image[x+1][y] == val) dfs(image, x+1, y, color, val);
        if (y+1 < image[0].size() && image[x][y+1] == val) dfs(image, x, y+1, color, val);
        if (x-1 >= 0 && image[x-1][y] == val) dfs(image, x-1, y, color, val);
        if (y-1 >= 0 && image[x][y-1] == val) dfs(image, x, y-1, color, val);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        int color = image[sr][sc];
        if (color != newColor) dfs(image, sr, sc, newColor, color);
        return image;
    }
};