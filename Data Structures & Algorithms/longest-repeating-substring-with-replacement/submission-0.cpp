class Solution {
public:
    int characterReplacement(string s, int k) {
vector<int> counts(26, 0); // To store frequency of each uppercase letter
    int left = 0;
    int maxCount = 0; // Frequency of the most common character in the current window
    int maxLength = 0;

    for (int right = 0; right < s.length(); right++) {
        // Increment count for the current character
        counts[s[right] - 'A']++;
        
        // Update the max frequency found in the current window
        maxCount = max(maxCount, counts[s[right] - 'A']);

        // Window size is (right - left + 1)
        // If (window size - maxCount) > k, we have more than k characters to replace
        while ((right - left + 1) - maxCount > k) {
            counts[s[left] - 'A']--;
            left++;
        }

        // Calculate the maximum length found so far
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
    }
};
