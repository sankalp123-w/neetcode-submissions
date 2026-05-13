class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
    if (nums.empty()) return res;
    int start = 0;
    while (start <= (int)nums.size() - k) {
        int currentMax = nums[start];
        int windowEnd = start + k; 
        for (int i = start; i < windowEnd; i++) {
            if (nums[i] > currentMax) {
                currentMax = nums[i];
            }
        }
        res.push_back(currentMax);
        start++;
    }
    
    return res;
    }
};
