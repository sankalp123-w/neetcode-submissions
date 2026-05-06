class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
    vector<int> res;
        int i =0, j=1;
        while (i<=num.size()-2){
            cout<<num[i]+num[j];
           if(num[i]+num[j]==target){
            res.push_back(i+1);
            res.push_back(j+1);
            return res;
           }
           if(j<num.size()-1){
            j++;
           }else{
            i++;
            j= i+1;
           }
        }
        return res;
    }
};
