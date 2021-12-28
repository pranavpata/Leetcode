class Solution {
public:
    int value(char c) {
        if (c == 'I') return 1;
        else if (c == 'V') return 5;
        else if (c == 'X') return 10;
        else if (c == 'L') return 50;
        else if (c == 'C') return 100;
        else if (c == 'D') return 500;
        return 1000;
    }
    
    int romanToInt(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'I' && i <= s.size() - 2 && (s[i+1] == 'V' || s[i + 1] == 'X')){
                sum += value(s[i + 1]) - value(s[i]);
                i++;
            }
            else if(s[i] == 'X' && i <= s.size() - 2 && (s[i+1] == 'L' || s[i + 1] == 'C')){
                sum += value(s[i + 1]) - value(s[i]);
                i++;
            }
            else if(s[i] == 'C' && i <= s.size() - 2 && (s[i+1] == 'D' || s[i + 1] == 'M')){
                sum += value(s[i + 1]) - value(s[i]);
                i++;
            }
            else{
                sum += value(s[i]);
            }
        }
        return sum;
    }
};