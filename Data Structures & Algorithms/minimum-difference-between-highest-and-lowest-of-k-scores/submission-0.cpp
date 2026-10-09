class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int mindiff = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i+k<=nums.size();i++){
            mindiff = min(mindiff,(nums[i+k-1]-nums[i]));
        }
        return mindiff;
    }
};