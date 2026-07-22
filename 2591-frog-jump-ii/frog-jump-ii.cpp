class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int result = stones[1] - stones[0];
        for (int i = 2; i < n; i++)
            result = max(result, stones[i] - stones[i-2]);

        return result;
    }
};