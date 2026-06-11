class Solution {
public:
    string decodeString(string s) {
        stack<int> freq;
        stack<string> prev;

        string curr;
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } 
            else if (ch == '[') {
                freq.push(num);
                prev.push(curr);
                num = 0;
                curr = "";
            } 
            else if (ch == ']') {
                string temp = prev.top();
                prev.pop();

                int repeat = freq.top();
                freq.pop();

                while (repeat--) {
                    temp += curr;
                }

                curr = temp;
            } 
            else {
                curr += ch;
            }
        }

        return curr;
    }
};