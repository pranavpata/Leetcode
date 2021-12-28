class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int toReturn = 0;
        int prev = timeSeries[0];
        for (int i = 1; i < timeSeries.size(); i++) {
            if (timeSeries[i] - prev < duration) {
                toReturn += timeSeries[i] - prev;
            }
            else {
                toReturn += duration;
            }
            prev = timeSeries[i];
        }
        toReturn += duration;
        return toReturn;
    }
};