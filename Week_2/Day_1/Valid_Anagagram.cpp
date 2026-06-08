class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr(122, 0);
        vector<int> brr(122, 0);
        bool flag = 0;
        if (s.size() != t.size()) {
            return 0;
        }
        for (int i = 0; i < s.size(); i++) {
            char idx = s[i] - 'a';
            int value = (int)idx;

            arr[value]++;
        }
        for (int i = 0; i < t.size(); i++) {
            char idx = t[i] - 'a';
            int value = (int)idx;

            brr[value]++;
        }

        for (int i = 0; i < 122; i++) {
            if (arr[i] != brr[i]) {
                return false;
            }
        }
        return true;
    }
};