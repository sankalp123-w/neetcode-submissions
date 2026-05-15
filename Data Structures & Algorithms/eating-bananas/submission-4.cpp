class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_k = *max_element(piles.begin(), piles.end());;
        sort(piles.begin(), piles.end());
        int left=1;
        int right = piles[piles.size()-1];
        while (left<=right){
            int mid = left + (right-left)/2;
            int k = mid;
            bool isvald = false;
            long long sum =0;
            for (int i=0;i<piles.size();i++){
                sum += (piles[i] + k - 1) / k;;
            }
            if (sum<=h){
                right = k-1;
                min_k = std::min(min_k, k);
            }else {
                left = k+1;
            }


        }
        return min_k; 
    }
    
};
