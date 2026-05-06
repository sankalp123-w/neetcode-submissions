class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<string> seen;
    
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            char val = board[r][c];
            
            if (val != '.') {
                // Formulate unique keys for the set
                string rowKey = "row" + to_string(r) + val;
                string colKey = "col" + to_string(c) + val;
                string boxKey = "box" + to_string(r/3) + to_string(c/3) + val;
                
                // If any key already exists, we found a duplicate
                if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                    return false;
                }
                
                seen.insert(rowKey);
                seen.insert(colKey);
                seen.insert(boxKey);
            }
        }
    }
    return true;
    }
};
