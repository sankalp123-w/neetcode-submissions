class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
vector<int> res;
    deque<int> dq; // Stores INDICES of elements

    for (int i = 0; i < nums.size(); i++) {
        // 1. Remove indices that are out of the current window range
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // 2. Remove indices of elements smaller than the current element
        // (They can never be the max for this or any future window)
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // 3. Add current element's index
        dq.push_back(i);

        // 4. If the window has reached size k, the front is the max
        if (i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
    }
};
