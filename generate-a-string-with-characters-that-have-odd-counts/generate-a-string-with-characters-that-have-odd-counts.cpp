class Solution {
public:
    string generateTheString(int n) {
        string toReturn = "";
        if (n%2 == 0) {
            for (int i = 0; i < n-1; i++) {
                toReturn += 'a';
            }
            toReturn += 'b';
        }
        else {
            for (int i = 0; i < n; i++) {
                toReturn += 'a';
            }
        }
        return toReturn;
    }
};