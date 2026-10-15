class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int maxIndex = 0;

        for(int i = 1; i < n; i++) {
            if(height[i] > height[maxIndex])
                maxIndex = i;
        }

        int water = 0;

        int leftMax = 0;

        for(int i = 0; i <= maxIndex; i++) {
            if(height[i] > leftMax)
                leftMax = height[i];
            else
                water += leftMax - height[i];
        }

        int rightMax = 0;

        for(int i = n - 1; i >= maxIndex; i--) {
            if(height[i] > rightMax)
                rightMax = height[i];
            else
                water += rightMax - height[i];
        }

        return water;
    }
};