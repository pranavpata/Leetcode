class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int n = inventory.size(); int mod = 1e9+7;
        long long toReturn = 0;
        sort(inventory.begin(), inventory.end());
        
        for (int j = n - 1; j >= 0 && orders; j--) {
            long long val = inventory[j];
            long long units = min((long long) orders, (n - j) * (val - (j ? inventory[j - 1] : 0)));                 
            long long itr = val - units / (n - j);
            toReturn = (toReturn + (n - j) * (val * (val + 1) - itr * (itr + 1)) / 2) % mod;
            toReturn = (toReturn + units % (n - j) * itr) % mod;
            orders-= units;
        }
        
        return toReturn;
        
        // int index = inventory.size()-1;
        // int max = inventory[index];
        // while (orders>0) {
        //     toReturn += inventory[index];
        //     inventory[index]--;
        //     if (index > 0 && inventory[index-1] == max) {
        //         index--;
        //     }
        //     else {
        //         index = inventory.size() - 1;
        //         max--;
        //     }
        //     orders--;
        // }
        // return toReturn%((long)(pow(10, 9)+7));
    }
};