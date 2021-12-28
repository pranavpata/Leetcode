class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int toReturn = -1;
        int minDist = INT_MAX;
        int dist;
        vector<int> point;
        for (int i = 0; i < points.size(); i++) {
            point = points[i];
            if (x == point[0] || y == point[1]) {
                dist = abs(x - point[0]) + abs(y - point[1]);
                if (minDist > dist) {
                    minDist = dist;
                    toReturn = i;
                }
            }
        }
        return toReturn;
    }
};