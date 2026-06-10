class Solution {
public:
    void lpsfind(vector<int>& lps, string s) {
        int first = 0;
        int second = 1;
        while (second < s.size()) {
            if (s[first] == s[second]) {
                lps[second]=first+1;
                first++, second++;
            } else {
                if (first == 0) {
                    lps[second] = 0;
                    second++;
                } else {
                    first = lps[first - 1];
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(), 0);
        lpsfind(lps, needle);
        int first = 0;
        int second = 0;
        while (first < haystack.size() && second < needle.size()) {
            if (haystack[first] == needle[second]) {
                first++;
                second++;
            } else {
                if (second == 0) {
                    first++;
                } else {
                    second = lps[second - 1];
                }
            }
        }
        if (second == needle.size())
            return first - second;

            return -1;
    }
};