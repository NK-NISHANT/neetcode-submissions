class Solution {
public:

    void helper(vector<pair<int,int>>& freq, int i,
                vector<int>& temp, vector<vector<int>>& ans) {

        if(i == freq.size()) {
            ans.push_back(temp);
            return;
        }

        int value = freq[i].first;
        int count = freq[i].second;

        for(int j = 0; j <= count; j++) {

            for(int k = 0; k < j; k++)
                temp.push_back(value);

            helper(freq, i + 1, temp, ans);

            for(int k = 0; k < j; k++)
                temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        unordered_map<int,int> mp;

        for(int x : nums)
            mp[x]++;

        vector<pair<int,int>> freq;

        for(auto p : mp)
            freq.push_back(p);

        vector<vector<int>> ans;
        vector<int> temp;

        helper(freq, 0, temp, ans);

        return ans;
    }
};