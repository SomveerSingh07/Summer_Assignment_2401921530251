class Solution {
public:
   
    vector<int> sortedSquares(vector<int>& nums) {

        vector<int> pos;
        vector<int> neg;

        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                pos.push_back(nums[i] * nums[i]);
            } else {
                neg.push_back(nums[i] * nums[i]);
            }
        }

       

        int n = pos.size();
        int m = neg.size();

        vector<int> final(n + m);

        int i = 0, j = 0, k = 0;

       
        while (i < n && j < m) {
            if (pos[i] <= neg[j]) {
                final[k++] = pos[i++];
            } else {
                final[k++] = neg[j++];
            }
        }

        while (i < n) {
            final[k++] = pos[i++];
        }

        while (j < m) {
            final[k++] = neg[j++];
        }

        return final;
    }
};
