class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int jwel;
      unordered_map<int, int> um;
       vector<int> ans;
      for (int i =0; i<=nums.size(); i++){
        jwel = target - nums[i];
        auto it = um.find(jwel);
        if(it != um.end()){
           ans.push_back(i);
           ans.push_back(um[jwel]);
           break;
        }
        um.insert({nums[i],i});
      }
      sort(ans.begin(), ans.end());
      return ans;
    }
};
