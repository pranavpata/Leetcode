class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int stick : sticks) {
            pq.push(stick);
        }
        int cost = 0;
        int first, second;
        while (pq.size() > 1) {
            first = pq.top();
            pq.pop();
            second = pq.top();
            pq.pop();
            cost += first + second;
            pq.push(first + second);
        }
        return cost;
    }
};