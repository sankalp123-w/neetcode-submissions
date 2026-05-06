class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    std::unordered_set<int> tempSet(nums.begin(), nums.end());
    
    // 2. Reassign back to a vector so we can sort and use pointers
    std::vector<int> sortedUnique(tempSet.begin(), tempSet.end());
    std::sort(sortedUnique.begin(), sortedUnique.end());

    int longestStreak = 1;
    int currentStreak = 1;
    int i =0; 
    int i2= 1;

     
     while ( (i<sortedUnique.size())&&(i2<sortedUnique.size()))
     {
        if (sortedUnique[max(i,i2)] == sortedUnique[min(i,i2)] + 1) {
            // They are consecutive!
            currentStreak++;

        } else {
            // The chain broke. Reset streak.
            currentStreak = 1;
        }
        if(i<i2) {i+=2;}else i2 +=2;
        longestStreak = max(longestStreak, currentStreak);
     }
    return longestStreak;


    }
};
