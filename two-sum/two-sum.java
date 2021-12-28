class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] toReturn = new int[2];
        int complement;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            complement = target - nums[i];
            if (map.containsKey(complement)) {
                toReturn[0] = map.get(complement);
                toReturn[1] = i;
                break;
            }
            map.put(nums[i], i);
        }
        return toReturn;
    }
}