class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;

        while (start < n) {
            int end = start;

            while (end < n && s[end] != ' ') {
                end++;
            }

            reverse(s.begin() + start, s.begin() + end);

            start = end + 1;
        }

        return s;
    }
};