class Solution {
public:
    int amount(int pre, int suf, int h) {
        return min(pre, suf) - h;
    }

    int trap(vector<int>& height) {
        // Options:
        // compute water capacity between 2 pointers
        // computer water capacity for a specific index
        // populate - gratest element to the left, greatest element to the right per index
        int n = height.size();
        vector<int> prefix(n, 0), suffix(n, 0);

        int curr = 0;
        for (int i = 0; i < n; i ++) {
            prefix[i] = curr;
            if (height[i] > curr) {
                curr = height[i];
            }
        }

        curr = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = curr;
            if (height[i] > curr) {
                curr = height[i];
            }
        }

        // cout << "prefix: ";
        // for (int i : prefix) cout << i << ' ';
        // cout << endl;

        // cout << "suffix: ";
        // for (int i : suffix) cout << i << ' ';
        // cout << endl;

        int res = 0;
        for (int index = 1; index < n - 1; index++) {
            if (prefix[index] > height[index] && suffix[index] > height[index]){
                res += amount(prefix[index], suffix[index], height[index]);
            }
            // cout << res << ' ';
        }        

        return res;
    }
};
