#include <cstring>
class Solution {
public:

    string encode(vector<string>& strs) {
     string strencoded; 
        for (int i = 0; i < strs.size(); ++i) {
    strencoded += to_string(strs[i].length())+"#"+strs[i]; 
}
        return strencoded;

    }

    vector<string> decode(string s) {
    vector<string> result;
    size_t i = 0;

    while (i < s.length()) {
        // 1. Find the delimiter '#' starting from current position i
        size_t j = s.find('#', i);
        
        // 2. Extract the length prefix and convert to integer
        // s.substr(pos, len)
        int length = std::stoi(s.substr(i, j - i));
        
        // 3. Extract the actual word
        // The word starts at j + 1 and has 'length' characters
        std::string word = s.substr(j + 1, length);
        result.push_back(word);
        
        // 4. Move pointer i to the beginning of the next prefix
        i = j + 1 + length;
    }

    return result;
         
    }
};
