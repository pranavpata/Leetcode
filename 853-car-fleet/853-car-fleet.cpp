class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> pos_time; //position, time
        
        for(int i = 0; i < position.size(); i++) {
            pos_time.push_back({position[i], double(target - position[i])/speed[i]});
        }
        sort(pos_time.begin(), pos_time.end());
        
        stack<double> fleets;
        
        for(auto pt: pos_time) {
            double time = pt.second;
            while (!fleets.empty() && time >= fleets.top()) {
                fleets.pop();
            }
            fleets.push(time);
        }
        
        return fleets.size();
    }
};