class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (!n) return 0;

        unordered_map<int, bool> mpp;

        for (int i : nums) mpp[i] = true;

        vector<int> candidates;
        for (auto &it : mpp) {
            if (mpp.find(it.first + 1) != mpp.end()) {
                candidates.push_back(it.first);
            } else continue;
        }

        sort(candidates.begin(), candidates.end(), greater<int>());
        // sequence exists: starting from x, len
        unordered_map<int, int> seq;
        int sequence_length = 1;

        for (int candidate : candidates) {
            int num = candidate;

            if (seq.find(num+1) != seq.end()) {
                seq[candidate] = seq[candidate+1]+1;
                sequence_length = max(sequence_length, seq[candidate]);
                continue;
            }

            while (mpp.find(num + 1) != mpp.end()) num++;

            seq[candidate] = num - candidate + 1;
            sequence_length = max(sequence_length, seq[candidate]);
        }

        return sequence_length;
    }
};
