class Solution {
public:
    int maxArea(vector<int>& heights) {
    int max_water = 0;
    int left = 0;
    int right = heights.size() - 1;

    while (left < right) {
        int width = right - left;
        int h = min(heights[left], heights[right]);
        
        max_water = max(max_water, h * width);

        // Move the pointer pointing to the shorter bar
        if (heights[left] < heights[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max_water;
    }
};
