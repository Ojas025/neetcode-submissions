class Solution {
public:

    bool isPalindrome(string s) {
        string str = "";

        for (char c : s) {
            if (isalnum(static_cast<unsigned char>(c))) {
                str += tolower(static_cast<unsigned char>(c));
            }
        }

        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }

        return true;
    }
};
