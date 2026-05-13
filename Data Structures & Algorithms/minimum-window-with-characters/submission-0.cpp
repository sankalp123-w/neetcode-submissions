class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

    // Array to store the frequency of characters in t
    vector<int> targetMap(128, 0);
    for (char c : t) targetMap[c]++;

    // Variables to track the window
    int left = 0, right = 0;
    int requiredChars = 0;
    for (int count : targetMap) if (count > 0) requiredChars++;
    
    int formed = 0;
    vector<int> windowMap(128, 0);

    // To store result: {length, start_index}
    int minLen = INT_MAX;
    int startIdx = 0;

    while (right < s.length()) {
        char c = s[right];
        windowMap[c]++;

        // If current character frequency matches the target frequency
        if (targetMap[c] > 0 && windowMap[c] == targetMap[c]) {
            formed++;
        }

        // Try to shrink the window from the left
        while (left <= right && formed == requiredChars) {
            c = s[left];

            // Save the smallest window found so far
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                startIdx = left;
            }

            // Remove character from window
            windowMap[c]--;
            if (targetMap[c] > 0 && windowMap[c] < targetMap[c]) {
                formed--;
            }
            left++;
        }
        right++;
    }

    return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};
