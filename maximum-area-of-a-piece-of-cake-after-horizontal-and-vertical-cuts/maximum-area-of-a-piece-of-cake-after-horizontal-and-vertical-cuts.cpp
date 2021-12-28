#include<algorithm>
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long toReturn = 0;
        int hMax = 0;
        int prev = 0;
        int current;
        for (int i = 0; i < horizontalCuts.size(); i++) {
            current = horizontalCuts[i];
            hMax = max(hMax, current - prev);
            prev = current;
        }
        hMax = max(hMax, h - prev);
        int wMax = 0;
        prev = 0;
        for (int i = 0; i < verticalCuts.size(); i++) {
            current = verticalCuts[i];
            wMax = max(wMax, current - prev);
            prev = current;
        }
        wMax = max(wMax, w - prev);
        //cout << wMax << " " << hMax << endl;
        toReturn = ((long)hMax*wMax)%((long)(pow(10, 9) + 7));
        return toReturn;
    }
};