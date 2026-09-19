class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;

        for(int i = 0; i< nums.size(); i++){
            int needed = target - nums[i];

            if(m.count(needed)) {
                return {m[needed], i};
            }
            m[nums[i]] = i;
        }

        return {-1, -1};
    }
};
