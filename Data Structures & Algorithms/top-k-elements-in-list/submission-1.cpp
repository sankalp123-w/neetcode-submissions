class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    vector<pair<int,int>>freq_vec;
    for (int n : nums) {
        counts[n]++;
    }

    for (auto entry : counts) {
    freq_vec.push_back({entry.second, entry.first});
}
    vector<int> res; 
    sort(freq_vec.begin(),freq_vec.end());

    while(k){
     res.push_back(freq_vec.back().second);
      freq_vec.pop_back();
      k--;
    }
      return res;
    }
};
