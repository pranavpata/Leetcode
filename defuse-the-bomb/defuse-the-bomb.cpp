class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> toReturn;
        int newIndex;
        int toAdd;
        for (int i = 0; i < code.size(); i++) {
            toAdd = 0;
            if (k > 0) {
                newIndex = i + 1;
                for (int j = 0; j < k; j++) {
                    if (newIndex == code.size()) {
                        newIndex = 0;
                    }
                    toAdd += code[newIndex++];
                }
            }
            else if (k < 0) {
                newIndex = i - 1;
                for (int j = 0; j > k; j--) {
                    if (newIndex == -1) {
                        newIndex = code.size() - 1;
                    }
                    toAdd += code[newIndex--];
                }
            }
            toReturn.push_back(toAdd);
        }
        return toReturn;
    }
};