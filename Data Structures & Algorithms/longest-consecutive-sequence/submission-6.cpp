class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (!n) return 0;

        unordered_map<int, bool> mpp;

        for (int i : nums) mpp[i] = true;

        // -----------------------------------------------------------
        // With this approach - you required an inherent order from the candidates


        // vector<int> candidates;
        // for (auto &it : mpp) {
        //     if (mpp.find(it.first + 1) != mpp.end()) {
        //         candidates.push_back(it.first);
        //     } else continue;
        // }

        // sort(candidates.begin(), candidates.end(), greater<int>());
        // // sequence exists: starting from x, len
        // unordered_map<int, int> seq;
        int sequence_length = 1;

        // for (int candidate : candidates) {
        //     int num = candidate;

        //     if (seq.find(num+1) != seq.end()) {
        //         seq[candidate] = seq[candidate+1]+1;
        //         sequence_length = max(sequence_length, seq[candidate]);
        //         continue;
        //     }

        //     while (mpp.find(num + 1) != mpp.end()) num++;

        //     seq[candidate] = num - candidate + 1;
        //     sequence_length = max(sequence_length, seq[candidate]);
        // }
        // -----------------------------------------------------------

        // Drop the need for sorting, go from bottom up
        for (int index = 0; index < n; index++) {
            int i = nums[index];

            // check if this is the starting element
            if (mpp.find(i-1) != mpp.end()) continue;

            int num = i;
            while (true) {
                if (mpp.find(num+1) != mpp.end()) {
                    num++;
                } else break;
            }

            sequence_length = max(sequence_length, num - i + 1);
        }        

        return sequence_length;
    }
};
