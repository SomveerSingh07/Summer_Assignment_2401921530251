class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i = 0; i < nums.size(); i++) {

            // remove elements outside the window
            if(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // remove smaller elements
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // store maximum after first window is formed
            if(i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};