class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    long long totalProduct = 1; 
    int zeroCount = 0;

    for (int num : nums) {
        if (num == 0) {
            zeroCount++;
        } else {
            totalProduct *= num;
        }
    }

    vector<int> res(nums.size()); 
    for (int i = 0; i < nums.size(); i++) {
        if (zeroCount > 1) {
            res[i] = 0;
        } else if (zeroCount == 1) {
            res[i] = (nums[i] == 0) ? totalProduct : 0;
        } else {
            res[i] = totalProduct / nums[i];
        }
    }
    return res;
    }
};
