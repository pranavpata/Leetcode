class Solution {
public:
    int reverse(int x) {
        int toReturn = 0;
        int pop;
        while (x != 0) {
            pop = x%10;
            x /= 10;
            if (toReturn > INT_MAX/10 || (toReturn == INT_MAX/10 && pop>7)) {
                return 0;
            }
            if (toReturn < INT_MIN/10 || (toReturn == INT_MIN/10 && pop<-8)) {
                return 0;
            }
            toReturn = toReturn * 10 + pop;
        }
        return toReturn;
    }
};