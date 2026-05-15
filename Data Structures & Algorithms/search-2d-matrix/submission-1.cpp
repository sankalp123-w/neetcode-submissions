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
        for(int i =0; i<=internlSize-1;i++){
            if(matrix[mid][i]==target){
                return true;
            }
        }
       }
       return false;
    }
};
