class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        // amount_of_water = (j - i) * min(heights[i], heights[j])
        // always move the smaller value ptr

        int left = 0;
        int right = n - 1;

        int maxAmount = 0;

        while (left < right) {
            int amount = (right - left) * min(heights[left], heights[right]);
            maxAmount = max(amount, maxAmount);

            if (heights[left] < heights[right]) left++;
            else right--;           
        }

        return maxAmount;
    }
};
