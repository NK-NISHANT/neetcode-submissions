class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<pair<int,int>> maxInt;

        for(int i = 0, left = 0; i < nums.size(); i++){

            while(!maxInt.empty() && maxInt.back().first < nums[i]){
                maxInt.pop_back();
            }

            maxInt.push_back(make_pair(nums[i], i));

            if(i - left + 1 == k){

                while(!maxInt.empty() && maxInt.front().second < left){
                    maxInt.pop_front();
                }

                ans.push_back(maxInt.front().first);
                left++;
            }
        }

        return ans;
    }
};