class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> triplets;

        for (int k = 0; k < n; k++) {
            if (k > 0 && nums[k] == nums[k-1]) continue;

            int target = nums[k];
            if (target != 0) target *= -1;

            int left = k + 1, right = n - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    triplets.push_back({nums[k],nums[left],nums[right]});
                    left++; right--;
                } else if (sum > target) right--;
                else if (sum < target) left++;
            }
        }

        triplets.erase(unique(triplets.begin(), triplets.end()), triplets.end());

        return triplets;
    }
};
