// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int mid;
        int toReturn = 1;
        while (low <= high) {
            mid = low + (high - low)/2;
            if (isBadVersion(mid)) {
                toReturn = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return toReturn;
    }
};