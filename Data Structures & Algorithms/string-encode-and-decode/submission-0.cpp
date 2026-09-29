class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string e = "";

        for (string s : strs) {
            // length of the string
            // delimiter
            // string

            e += to_string(s.length()) + '#' + s;
        }

        return e;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int index = 0;

        while (index < s.length()) {
            int delimiter_index = s.find('#', index);
            int len = stoi(s.substr(index, delimiter_index - index));

            strs.push_back(s.substr(delimiter_index+1, len));

            index = delimiter_index + len + 1;
        }

        return strs;
    }
};
