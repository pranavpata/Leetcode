class Solution {
public:
    int minSwaps(vector<int>& data) {
        int windowSize = 0;
        for (int num : data) {
            windowSize += num;
        }
        int cur1 = 0, max1 = 0;
        int left = 0, right = 0;
        while (right < data.size()) {
            cur1 += data[right];
            right++;
            if (right - left > windowSize) {
                cur1 -= data[left];
                left++;
            }
            max1 = max(max1, cur1);
        }
        return windowSize - max1;
    }
};