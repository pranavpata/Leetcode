class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        vector<int> nums(10, 0);
        //guess is positive, secret is negative
        for (int i = 0; i < secret.size(); i++) {
            int g = guess[i] - '0';
            int s = secret[i] - '0';
            if (g == s) bulls++;
            else {
                if (nums[g] < 0) cows++;
                if (nums[s] > 0) cows++;
                nums[g]++;
                nums[s]--;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};