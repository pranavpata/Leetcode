class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int result = 0;
        int size = cardPoints.size();
        vector<int> left(size);
        vector<int> right(size);
        int leftCur = 0, rightCur = 0;
        for (int i = 0; i < size; i++) {
            leftCur += cardPoints[i];
            left[i] = leftCur;
            rightCur += cardPoints[size - i -1];
            right[size - i - 1] = rightCur;
        }
        
        left.insert(left.begin(), 0);
        right.push_back(0);
        
        for (int i = 0; i <= k; i++) {
            result = max(result, left[i] + right[size - (k - i)]);
        }
        return result;
    }
};