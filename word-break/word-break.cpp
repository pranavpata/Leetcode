class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> breaks(s.length() + 1, 0);
        breaks[0] = 1;
        for (int i = 0; i < breaks.size(); i++) {
            if (breaks[i]) {
                for (string word: wordDict) {
                    if (i + word.length() < breaks.size()  && s.substr(i, word.length()) == word) {
                        breaks[i + word.length()] = 1;
                    }
                }
            }
        }
        return breaks.back();
    }
};