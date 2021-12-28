class Solution {
public:
    int minSteps(string s, string t) {
        int letters[2][26] = {};
        
        //get total number of letters
        for (int i = 0; i < s.size(); i++) {
            letters[0][s[i] - 97]++;
            letters[1][t[i] - 97]++;
        }
        
        int toReturn = 0;
        for (int i = 0; i < 26; i++) {
            toReturn += abs(letters[0][i] - letters[1][i]);
        }
        return toReturn/2;
    }
};