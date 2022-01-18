class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int mn = 0;
        int reach = 0;
        int taps = 0;
        
        while(reach < n){
            for(int i=0; i<ranges.size(); i++){
                if(i-ranges[i] <= mn && i+ranges[i] > reach)
                    reach = i + ranges[i];
            }
            if(mn == reach) return -1;
            taps++;
            mn = reach;
         }
         return taps;
    }
};