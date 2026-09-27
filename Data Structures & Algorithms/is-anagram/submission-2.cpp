class Solution {
public:
    bool isAnagram(string s, string t) {
        int right = 0;

        int n = s.length();

        if (n != t.length()) return false;

        vector<int> a(26, 0);
        vector<int> b(26, 0);

        for (int i = 0; i < n; i++) {
            a[s[i] - 'a']++;
            b[t[i] - 'a']++;
        }

        return a == b;
    }
};
