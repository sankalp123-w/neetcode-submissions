class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l<=r) {
            int mid = l + (r - l) / 2;
if (nums[mid] == target) {
            return mid;
        }
          if (nums[l] <= nums[mid]) {
            // Step 2: Check if target lies within the sorted left half
            if (target >= nums[l] && target < nums[mid]) {
                r = mid - 1; // Search left
            } else {
                l = mid + 1; // Search right
            }
        }// Step 3: Otherwise, the right half must be normally sorted
        else {
            // Step 4: Check if target lies within the sorted right half
            if (target > nums[mid] && target <= nums[r]) {
                l = mid + 1; // Search right
            } else {
                r = mid - 1; // Search left
            }
        }
        }

            return -1;
    }
};
