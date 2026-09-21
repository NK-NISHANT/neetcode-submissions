class Solution {
public:

    void helper(vector<int>& nums, vector<int>& temp, int i,
                vector<vector<int>>& ans) {

        if(i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        helper(nums, temp, i + 1, ans);
        temp.pop_back();

        int j = i;

        while(j + 1 < nums.size() && nums[j] == nums[j + 1])
            j++;

        helper(nums, temp, j + 1, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        helper(nums, temp, 0, ans);

        return ans;
    }
};