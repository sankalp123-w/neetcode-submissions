class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int currstrig =0;
        int longeststr =0;
        string str=""; 
       for(int i = 0; i < s.size(); ++i) {
    size_t pos = str.find(s[i]);
    
    if(pos == std::string::npos) {
        str += s[i];
        currstrig++;
    } else {
        // 2. IMPORTANT: Keep the characters AFTER the duplicate
        // Example: if str is "dv" and s[i] is 'd', pos is 0. 
        // new str becomes "v" + "d" = "vd"
        str = str.substr(pos + 1) + s[i];
        currstrig = str.size();
    }
    longeststr = max(longeststr, currstrig); 
}
        return longeststr;

    }
};
