class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int toReturn = 0;
        int prev = 0;
        int current;
        for (int i = 0; i < rungs.size(); i++) {
            current = rungs[i];
            if (current - prev > dist) {
                if ((current-prev)%dist == 0) {
                    toReturn += (current-prev)/dist - 1;
                }
                else {
                    toReturn += (current-prev)/dist;
                }
            }
            prev = current;
        }
        return toReturn;
    }
};