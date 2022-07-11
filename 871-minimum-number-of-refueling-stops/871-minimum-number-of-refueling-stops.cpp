class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;
        int result = 0;
        int prev = 0;
        int fuel = startFuel;
        for(vector<int> station: stations) {
            int loc = station[0];
            int cap = station[1];
            fuel -= loc - prev;
            //need to refuel
            while (!maxHeap.empty() && fuel < 0) {
                fuel += maxHeap.top();
                maxHeap.pop();
                result++;
            }
            if (fuel < 0) return -1;
            maxHeap.push(cap);
            prev = loc;
        }
        
        // last station = target
        fuel -= target - prev;
        while (!maxHeap.empty() && fuel < 0) {
                fuel += maxHeap.top();
                maxHeap.pop();
                result++;
        }
        if (fuel < 0) return -1;
        
        return result;
    }
};