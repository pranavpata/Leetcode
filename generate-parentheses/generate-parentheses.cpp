class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> toReturn;
        recurse(toReturn, "", n, 0, 0);
        return toReturn;
    }
    
    void recurse(vector<string>& toReturn, string s, int n, int index, int endCount) {
        if (s.size() == n*2) {
            toReturn.push_back(s);
            return;
        }
        else if (s.size() == n*2 - 1) {
            toReturn.push_back(s+")");
            return;
        }
        if (index<n) {
            recurse(toReturn, s+"(", n, index+1, endCount+1);
        }
        if (endCount > 0) {
            recurse(toReturn, s+")", n, index, endCount-1);
        }
    }
};