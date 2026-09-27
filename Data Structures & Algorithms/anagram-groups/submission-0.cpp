class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mpp;

        for (string s : strs) {
            vector<int> freq(26, 0);
            for (char ch : s) {
                freq[ch - 'a']++;
            }

            if (mpp.find(freq) != mpp.end()) {
                mpp[freq].push_back(s);
            } else mpp[freq] = {s}; 
        }

        vector<vector<string>> res;
        for (auto it : mpp) {
            res.push_back(it.second);
        }

        return res;
    }
};
