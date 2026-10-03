class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, bool> exists;

        if (n <= 1) return n;

        int left = 0;
        int right = left + 1;

        exists[s[left]] = true;
        
        int maxLen = 0;
        while (right < n) {
            if (exists.find(s[right]) != exists.end()) {
                // remove s[left++]
                if (s[left] == s[right]) {
                    exists.erase(s[left]);
                    left++;
                } else {
                    while (s[left] != s[right]) {
                        exists.erase(s[left++]);
                    }

                    exists.erase(s[left++]);
                }
            }

            // add s[right++]
            exists[s[right++]] = true;

            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};
