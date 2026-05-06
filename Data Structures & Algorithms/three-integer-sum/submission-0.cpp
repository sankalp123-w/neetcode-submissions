#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end()); // Sort to use two-pointer approach

        for (int i = 0; i < nums.size(); i++) {
            // Optimization: If the current smallest number is > 0, 
            // no three numbers can sum to 0.
            if (nums[i] > 0) break;

            // Skip duplicate values for the first element 'i'
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++; // Need a larger value
                } else if (sum > 0) {
                    right--; // Need a smaller value
                } else {
                    // Found a triplet
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move pointers and skip duplicates for 'left' and 'right'
                    int last_left = nums[left];
                    int last_right = nums[right];
                    while (left < right && nums[left] == last_left) left++;
                    while (left < right && nums[right] == last_right) right--;
                }
            }
        }
        return res;
    }
};