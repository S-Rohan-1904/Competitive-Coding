#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i < r; i++)
#define eb emplace_back
#define nline '\n'
#define vi vector<int>
#define vvi vector<vi>
#define all(a) (a).begin(), (a).end()

const int INF = 1e9 + 1;

int n, m;
vvi g;
vi vis;
vi dist;
vi par;

void bfs(int start_node) {
    queue<int> q;
    q.push(start_node);
    dist[start_node] = 0;
    par[start_node] = INF;
    vis[start_node] = 1;
    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(auto v : g[front]) {
            if(!vis[v]) {
              vis[v] = 1;
              q.push(v);
              par[v] = front;
              dist[v] = dist[front] + 1;
            }
        } 
    }
}


void solve()
{
  cin >> n >> m;
  
  g.assign(n + 1, vi());
  vis.assign(n + 1, 0);
  dist.assign(n + 1, INF);
  par.assign(n + 1, 0);

  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    g[u].eb(v);
    g[v].eb(u);
  }

  bfs(1);

  if(dist[n] >= INF) {
    cout << "IMPOSSIBLE" << nline;
  } else {
    cout << dist[n] + 1 << nline;
    int curr = n;
    vi path;
    
    while(curr != INF) {
      path.eb(curr);
      curr = par[curr];
    }
    
    reverse(all(path));
    for(auto &el : path) cout << el << " ";
    cout << nline;
  }
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}