class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        int prefix = 1;
        int postfix = 1;

        for (int index = 0; index < n; index++) {
            res[index] = prefix;
            prefix *= nums[index]; 
        }

        for (int index = n - 1; index >= 0; index--) {
            res[index] *= postfix;
            postfix *= nums[index];
        }
        
        return res;
    }
};
