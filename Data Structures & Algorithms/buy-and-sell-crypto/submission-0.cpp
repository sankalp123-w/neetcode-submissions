class Solution {
public:
int maxProfit(vector<int>& prices) {
    int min_price = INT_MAX;
    int max_profit = 0;
    
    for (int price : prices) {
        // Update the lowest price found so far
        min_price = std::min(min_price, price);
        // Calculate profit if sold today and update max
        max_profit = std::max(max_profit, price - min_price);
    }
    
    return max_profit;
}
};
