class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, pair<int,int>>> q;

        q.push({0, {src, 0}});

        while (!q.empty()) {

            auto curr = q.front();
            q.pop();

            int stops = curr.first;
            int node = curr.second.first;
            int cost = curr.second.second;

            if (stops > k)
                continue;

            for (auto &it : adj[node]) {

                int next = it.first;
                int price = it.second;

                if (cost + price < dist[next]) {

                    dist[next] = cost + price;

                    q.push({stops + 1,
                            {next, cost + price}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};