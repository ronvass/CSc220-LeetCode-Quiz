class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // prices[i] is cheapest known cost to reach city i from src
        int INF = 1e9; // Initialized to infinity, which is basically unreachable
        vector<int> prices(n, INF);
        prices[src] = 0; // cost to reach source is 0

        // Do k+1 iterations because k stops = k+1 edges
        for (int i = 0; i <= k; i++) {
            // Current prices should be copied before this round to prevent using edges updated in the same iteration
            vector<int> temp = prices;

            // Try every edge and relax if a cheaper path is found
            for (int j = 0; j < flights.size(); j++) {
                int from = flights[j][0];
                int to = flights[j][1];
                int price = flights[j][2];

                if (prices[from] == INF)
                    continue;

                if (prices[from] + price < temp[to])
                    temp[to] = prices[from] + price;
            }
            prices = temp;
        }
        if (prices[dst] == INF)
            return -1;

        return prices[dst];
    }
};