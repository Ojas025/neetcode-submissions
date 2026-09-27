class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Find 2 elements, one from each vector - whose sum == target
        // sorting distorts the original indices
        int n = nums.size();
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            int q = target - nums[i];
            if (mpp.find(q) != mpp.end()) {
                return {mpp[q], i};
            } else {
                mpp[nums[i]] = i;
            }
        }

        return {};
    }
};
