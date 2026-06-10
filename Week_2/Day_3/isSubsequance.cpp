class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIndex = 0;

        for (char ch : t) {
            if (sIndex < s.size() && ch == s[sIndex]) {
                sIndex++;
            }
        }

        return sIndex == s.size();
    }
};