class Solution {
public:
    static bool myFunc(vector<int> one, vector<int> two) {
        return one[1] > two[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int toReturn = 0;
        sort(boxTypes.begin(), boxTypes.end(), myFunc);
        int index = 0;
        vector<int> boxType;
        while (truckSize > 0 && index<boxTypes.size()) {
            boxType = boxTypes[index];
            int numBoxes = min(boxType[0], truckSize);
            toReturn += numBoxes*boxType[1];
            truckSize -= numBoxes;
            index++;
        }
        return toReturn;
    }
};