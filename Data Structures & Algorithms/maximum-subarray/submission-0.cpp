class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxS = nums[0];
        int tempS = nums[0];
        for(int i=1;i<nums.size();i++){
            if(tempS<0){
                tempS=0;
            }
            tempS+=nums[i];
            maxS=max(tempS,maxS);
        }
        return maxS;
    }
};
