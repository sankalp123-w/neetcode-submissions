class Solution {
public:
    int findMin(vector<int> &nums) {
       int l = 0;
int r = nums.size() - 1;

// Use l < r so the loop terminates exactly when l and r meet
while (l < r) {
    int mid = l + (r - l) / 2;

    if (nums[mid] > nums[r]) {
        // Minimum must be in the right half
        l = mid + 1;
    } else {
        // Minimum is mid or in the left half
        r = mid;
    }
}

// When l == r, both pointers point to the minimum element
return nums[l];
    }
};
