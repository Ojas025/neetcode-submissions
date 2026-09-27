class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i : nums) {
            if (mpp[i] == 0) {
                mpp[i] += 1;
            } else {
                if (mpp[i] == 1) {
                    return true;
                }
            }
        }

        return false;
    }
};