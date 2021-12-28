class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int prev = 1;
        int prev_prev = 1;
        
        for (int i = 1; i < s.size(); i++) {    
            int currentWays = 0;
            int a = s[i] - '0';
            int b = (s[i-1] - '0')*10 + a;
            if (a > 0 & a <= 9) currentWays += prev;
            if (b >= 10 && b <= 26) currentWays += prev_prev;
            prev_prev = prev;
            prev = currentWays;
        }
        
        return prev;
    }
};