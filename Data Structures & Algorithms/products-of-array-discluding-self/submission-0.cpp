class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix;
        vector<int> suffix(n);

        // Issues with only using prefix product:
        // - 0 corrupts the prefix
        // - requirement of a division operation

        int pre_prod = 1;
        int suf_prod = 1;

        for (int index = 0; index < n; index++) {
            pre_prod *=  nums[index];
            suf_prod *= nums[n - index - 1];

            prefix.push_back(pre_prod);
            suffix[n - index - 1] = suf_prod;
        }

        vector<int> res;

        for (int index = 0; index < n; index++) {
            int pref, suf;
            if (index - 1 < 0) {
                pref = 1;
            } else {
                pref = prefix[index - 1];
            }

            if (index + 1 >= n) {
                suf = 1;
            } else {
                suf = suffix[index + 1];
            }

            res.push_back(pref * suf);
        }

        return res;
    }
};
