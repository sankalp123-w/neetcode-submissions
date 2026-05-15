class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if (matrix.empty() || matrix[0].empty()) return false;

    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int left = 0;
    int right = (rows * cols) - 1; // Correct upper bound

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Map the 1D 'mid' index back to 2D coordinates
        int midValue = matrix[mid / cols][mid % cols];

        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1; // Search the right half
        } else {
            right = mid - 1; // Search the left half
        }
    }

    return false;
    }
};
