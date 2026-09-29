class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0;
        int jumps=0;
        while(i<nums.size()-1){
            int maxReach = -1;
            int maxidx = 0;
            if(i + nums[i] >= nums.size() - 1)
                return jumps + 1;
            for(int j=i+1;j<=i+nums[i] && j<nums.size();j++){
                if(j+nums[j]>maxReach){
                    maxReach = j+nums[j];
                    maxidx = j;
                }
            }
            i = maxidx;
            jumps++;
        }
        return jumps;
    }
};