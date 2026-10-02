class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int res = 0;
        int curr = prices[n - 1];

        for (int index = n - 2; index >= 0; index--) {
            int diff = curr - prices[index];
            res = max(res, diff);

            curr = max(curr, prices[index]);
        }

        return res;
    }
};
