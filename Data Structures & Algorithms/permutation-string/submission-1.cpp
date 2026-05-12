class Solution {
public:
    bool checkInclusion(string s1, string s2) {
int n1 = s1.size(), n2 = s2.size();
    if (n1 > n2) return false;

    // Use arrays as frequency maps for 'a'-'z'
    vector<int> s1_count(26, 0), s2_count(26, 0);

    // Initialize the maps with the first window
    for (int i = 0; i < n1; i++) {
        s1_count[s1[i] - 'a']++;
        s2_count[s2[i] - 'a']++;
    }

    // Slide the window across s2
    for (int i = 0; i < n2 - n1; i++) {
        if (s1_count == s2_count) return true;

        // Move window: add next char, remove oldest char
        s2_count[s2[i + n1] - 'a']++;
        s2_count[s2[i] - 'a']--;
    }

    // Check the last window
    return s1_count == s2_count;
    }
};
