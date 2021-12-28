class Solution {
public:
    
    int size;
    vector<string> toReturn;
    string dig;
    
    vector<string> letterCombinations(string digits) {
        size = digits.size();
        dig = digits;
        if (size > 0) {
            combinations("", 0);
        }
        return toReturn;
    }
    
    
    void combinations(string word, int num) {
        if (num == size) {
            toReturn.push_back(word);
            return;
        }
        int newNum = num + 1;
        switch(dig[num]) {
                case '2':
                    combinations(word + 'a', newNum);
                    combinations(word + 'b', newNum);
                    combinations(word + 'c', newNum);
                    break;
                case '3':
                    combinations(word + 'd', newNum);
                    combinations(word + 'e', newNum);
                    combinations(word + 'f', newNum);
                    break;
                case '4':
                    combinations(word + 'g', newNum);
                    combinations(word + 'h', newNum);
                    combinations(word + 'i', newNum);
                    break;
                case '5':
                    combinations(word + 'j', newNum);
                    combinations(word + 'k', newNum);
                    combinations(word + 'l', newNum);
                    break;
                case '6':
                    combinations(word + 'm', newNum);
                    combinations(word + 'n', newNum);
                    combinations(word + 'o', newNum);
                    break;
                case '7':
                    combinations(word + 'p', newNum);
                    combinations(word + 'q', newNum);
                    combinations(word + 'r', newNum);
                    combinations(word + 's', newNum);
                    break;
                case '8':
                    combinations(word + 't', newNum);
                    combinations(word + 'u', newNum);
                    combinations(word + 'v', newNum);
                    break;
                case '9':
                    combinations(word + 'w', newNum);
                    combinations(word + 'x', newNum);
                    combinations(word + 'y', newNum);
                    combinations(word + 'z', newNum);
                    break;
            }
    }
    
};