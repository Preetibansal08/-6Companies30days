class Solution {
public:
#define P pair<int, int>
    void dijkstra(int n, unordered_map<int, vector<P>>& adj,vector<int>& result, int S) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, S});
        fill(result.begin(), result.end(), INT_MAX);
        result[S] = 0;

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& p : adj[node]) {
                int adjNode = p.first;
                int dist = p.second;

                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
    }
    int findResCity(int n, vector<vector<int>>& sortPathMatrix, int D) {
        int resultCity = -1;
        int leastReachCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            int countReach = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && sortPathMatrix[i][j] <= D) {
                    countReach++;
                }
            }
            if (countReach <= leastReachCount) {
                leastReachCount = countReach;
                resultCity = i;
            }
        }
        return resultCity;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> sortPathMatrix(n, vector<int>(n, 1e9 + 7));

        for (int i = 0; i < n; i++) {
            sortPathMatrix[i][i] = 0;
        }
        unordered_map<int, vector<P>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        for (int i = 0; i < n; i++) {
            dijkstra(n, adj, sortPathMatrix[i], i);
        }

        // find the city by iterating over shortestPathMatrix
        return findResCity(n, sortPathMatrix, distanceThreshold);
    }
};
