class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int right = 0, left = 0; right < nums.size(); right++) {

            while(!dq.empty() && nums[dq.back()] < nums[right])
                dq.pop_back();

            dq.push_back(right);

            if(dq.front() < left)
                dq.pop_front();

            if(right - left + 1 == k) {
                ans.push_back(nums[dq.front()]);
                left++;
            }
        }

        return ans;
    }
};