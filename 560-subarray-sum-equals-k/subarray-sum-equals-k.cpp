class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;

        int currentSum = 0, count = 0;

        for (int num : nums) {
            currentSum += num;

            count += prefixCount[currentSum - k];
            prefixCount[currentSum]++;
        }

        return count;
    }
};