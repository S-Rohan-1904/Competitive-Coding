int n;
vector<pair<int,int>> g;
void dijkstra(int start) {
    priority_queue<pii> pq; 
    dist[start] = 0;
    pq.push({0, start}); 

    while (!pq.empty()) {
        int d = -pq.top().first;
        int u = pq.top().second; 
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto &edge : g[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({-dist[v], v});
            }
        }
    }
}