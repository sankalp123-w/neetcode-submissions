class Solution {
public:
    int maxArea(vector<int>& heights) {
    int n = heights.size();
    if (n < 2) return 0;

    // Create a list of pairs (height, original_index)
    std::vector<std::pair<int, int>> nodes;
    for (int i = 0; i < n; ++i) {
        nodes.push_back({heights[i], i});
    }

    // Sort by height descending
    std::sort(nodes.rbegin(), nodes.rend());

    int max_water = 0;
    // Track the leftmost and rightmost indices seen so far
    int min_idx = nodes[0].second;
    int max_idx = nodes[0].second;

    for (const auto& node : nodes) {
        int current_h = node.first;
        int current_i = node.second;

        // Update bounds of bars taller than or equal to current_h
        min_idx = std::min(min_idx, current_i);
        max_idx = std::max(max_idx, current_i);

        // Calculate area with the furthest bar seen so far
        int area1 = current_h * std::abs(current_i - min_idx);
        int area2 = current_h * std::abs(current_i - max_idx);

        max_water = std::max({max_water, area1, area2});
    }

    return max_water;
    }
};
