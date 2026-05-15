class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       if (matrix.empty() || matrix[0].empty()) return false;
       int internlSize = matrix[0].size();
       int left = 0; 
       int right =  matrix.size()-1;
       while (left<=right){
        int mid = left + (right-left)/2;
        if(matrix[mid][internlSize-1]>target){
            right = mid-1;
        }
        if(matrix[mid][0]<target){
            left = mid+1;
        }
        int rl =0 ; 
        int rr = internlSize-1;
        while ( rl<=rr){
        int midr = rl + (rr-rl)/2;
        if(matrix[mid][midr]>target){
            rr = midr-1;
        }
        if(matrix[mid][midr]<target){
            rl = midr+1;
        }
        if(target == matrix[mid][midr])
        {
            return true;
        }
        }
       }
       return false;
    }
};
