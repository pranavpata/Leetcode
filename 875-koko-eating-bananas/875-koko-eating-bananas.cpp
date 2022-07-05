class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //binary search from 1 to max of piles
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = (left + right)/2;
            int hours = 0;
            for (int pile : piles) {
                hours += ceil((double)pile/mid);
            }
            if (hours <= h) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return right;

    }
};