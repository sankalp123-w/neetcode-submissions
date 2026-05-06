class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> um;
    vector<vector<string>> res;
       for(int i = 0; i < strs.size(); i++){
        string x = strs[i];
        sort(x.begin(), x.end());
        um[x].push_back(strs[i]);
       }
       for(auto it = um.begin(); it != um.end(); it++){
           res.push_back(it->second);
       }
       return res; 
    }
};