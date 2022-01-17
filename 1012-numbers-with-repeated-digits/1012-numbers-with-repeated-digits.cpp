class Solution {
public:
    int permutation(int m,int n){
        if(n==0)return 1;
        return (m-n+1)*permutation(m,n-1);
    }
    
    int numDupDigitsAtMostN(int N) {
        vector<int>num;
        int number=N;
        N=N+1;
        while(N>0){                // storing all digits 
            num.push_back(N%10);
            N=N/10;
        }
        reverse(num.begin(),num.end());    
        int n=num.size();
        int res=0;
        for(int i=0;i<n-1;i++){         //calculate all numbers which have less digits than in N
            res+=9*permutation(9,i);
        }
        unordered_set<int>seen;
/*calculate number which have same disits as N and not contain any two digits same ans less than N */
        for(int i=0;i<n;i++){  
            for(int j=i>0?0:1;j<num[i];j++){  //check for which is less than current digit in N 
                if(seen.find(j)==seen.end()){  //check if it has not visited yet
                    res+=permutation(9-i,n-i-1);
                }
            }
            if(seen.find(num[i])!=seen.end()) break;  //if a number is repeated in N itself no more number possible which are less and not contain duplicate
            seen.insert(num[i]);   //mark as seen current digit
        }
        return number-res;
    }
};