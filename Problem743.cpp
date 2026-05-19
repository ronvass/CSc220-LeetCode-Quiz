class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // Build adjacency list: adj[u] = list of {v, weight}
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        // dist[i] = shortest known distance from source k to node i
        // Initialize all distances to infinity
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0; // Distance to source is 0

        // Min-heap priority queue: {distance, node}
        // Always processes the closest unvisited node next
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, k}); // Start from source node k with cost 0

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // Skip if we already found a better path to u
            if (d > dist[u]) continue;

            // Relax all neighbors of u
            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;        // Update shortest distance
                    pq.push({dist[v], v});          // Push updated distance to queue
                }
            }
        }

        // The answer is the maximum distance across all nodes
        // (last node to receive the signal = bottleneck)
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1; // Node unreachable
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
