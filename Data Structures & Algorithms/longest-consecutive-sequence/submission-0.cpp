class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

    // 1. Remove duplicates using a set
    std::unordered_set<int> tempSet(nums.begin(), nums.end());
    
    // 2. Reassign back to a vector so we can sort and use pointers
    std::vector<int> sortedUnique(tempSet.begin(), tempSet.end());
    std::sort(sortedUnique.begin(), sortedUnique.end());

    int longestStreak = 1;
    int currentStreak = 1;

    // 3. Use two pointers (i and i+1) to check the gap
    for (size_t i = 0; i < sortedUnique.size() - 1; ++i) {
        if (sortedUnique[i + 1] == sortedUnique[i] + 1) {
            // They are consecutive!
            currentStreak++;
        } else {
            // The chain broke. Reset streak.
            currentStreak = 1;
        }
        longestStreak = std::max(longestStreak, currentStreak);
    }

    return longestStreak;


    }
};
