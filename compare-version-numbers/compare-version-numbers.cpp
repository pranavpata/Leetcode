class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (i < version1.size() || j < version2.size()){            
            int num1 = 0, num2 = 0;
            int k = i, l = j;
            for (; k < version1.size() && version1[k] != '.'; k++){
                num1 = num1*10 + (version1[k] - '0');
            }
            i = k + 1;
            for (; l < version2.size() && version2[l] != '.'; l++){
                num2 = num2*10 + (version2[l] - '0');
            }
            j = l + 1;            
            if (num1 < num2){
                return -1;
            }
            else if (num1 > num2){
                return 1;
            }
        }
        return 0;
    }
};