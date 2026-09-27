class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Find 2 elements, one from each vector - whose sum == target
        // sorting distorts the original indices
        int n = nums.size();
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++){
            mpp[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int q = target - nums[i];
            if (mpp[q] != 0 && mpp[q] != i) {
                if (mpp[q] > i) {
                    return {i, mpp[q]};
                } else return {mpp[q], i};
            }
        }        

        return {};
    }
};
