class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int i : nums) {
            mpp[i]++;
        }

        map<int, vector<int>, greater<int>> buckets;
        for (auto it : mpp) {
            buckets[it.second].push_back(it.first);
        }

        vector<int> res;
        for (auto it : buckets) {
            if (k != 0) {
                if (k >= it.second.size()) {
                    res.insert(res.end(), it.second.begin(), it.second.end());
                    k -= it.second.size();
                } else {
                    for (int i = it.second.size() - 1; i >= 0 && k != 0; i--) {
                        res.push_back(it.second[i]);
                        k--;
                    }
                }
            } else break;
        }
        
        return res;
    }
};
