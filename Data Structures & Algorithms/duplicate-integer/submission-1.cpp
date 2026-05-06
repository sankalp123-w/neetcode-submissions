class Solution {
unordered_set<int> us;
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size()<=0){
            return false;
        }
      for (int i = 0; i<=nums.size();i++){
        auto it = us.find(nums[i]);
        if (it!=us.end()){
            return true;
        }
        us.insert(nums[i]);
      }
      return false;
    }
};