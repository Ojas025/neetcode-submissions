class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> suffix(n, 0);

        int curr = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (prices[i] > curr) {
                curr = prices[i];
            }
            suffix[i] = max(curr, prices[i]);
        }

        int res = 0;
        for (int index = 0; index < n; index++) {
            res = max(res, suffix[index] - prices[index]);
        }

        return res;
    }
};
