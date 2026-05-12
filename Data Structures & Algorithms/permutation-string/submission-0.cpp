class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

    int n = s1.size();
    sort(s1.begin(), s1.end()); // Sort s1 once

    // Loop until s2.size() - n to prevent out-of-bounds
    for (int i = 0; i <= (int)s2.size() - n; i++) {
        // Extract a substring of CONSTANT length n
        string cur = s2.substr(i, n);
        
        sort(cur.begin(), cur.end());
        
        if (s1 == cur) {
            return true;
        }
    }
    return false;
    }
};
