class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea = 0;
        int n = heights.size()-1;
        int left = 0, right = n;
        while(left<right){
            int height = min(heights[left],heights[right]);
            int width = right-left;
            maxarea = max(maxarea,height*width);
            if(heights[left]<=heights[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxarea;
    }
};
