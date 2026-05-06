class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 
                        43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    
   unordered_map<unsigned long long, vector<string>> um;
    vector<vector<string>> res;
      for (const string& s : strs) {
            unsigned long long product = 1;
            for (char c : s) {
                // Map ASCII 'a' to primes[0], 'b' to primes[1], etc.
                product *= primes[c - 'a'];
            }
            um[product].push_back(s);
        }

        // Extract the grouped vectors
        for (auto& pair : um) {
            res.push_back(pair.second);
        }

        return res;
    }
};