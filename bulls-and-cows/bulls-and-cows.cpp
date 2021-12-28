class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        int sec[10] = {0};
        int gs[10] = {0};
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
            else {
                if (sec[guess[i] - '0'] > 0) {
                    sec[guess[i] - '0']--;
                    cows++;
                }
                else {
                    gs[guess[i] - '0']++;
                }
                
                if (gs[secret[i] - '0'] > 0) {
                    gs[secret[i] - '0']--;
                    cows++;
                }
                else {
                    sec[secret[i] - '0']++;
                }
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};