class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> counts;
        counts.push_back(1);
        int countIndex = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] == arr[i - 1]) {
                counts[countIndex]++;
            }
            else {
                counts.push_back(1);
                countIndex++;
            }
        }
        sort(counts.begin(), counts.end());
        int result = 0;
        for (int i = counts.size() - 1; i >= 0; i--) {
            size -= counts[i];
            result++;
            if (size <= arr.size()/2) return result;
        }
        return -1;
    }
};