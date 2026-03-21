#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i < r; i++)
#define rrep(i, r, l) for (int i = r-1; i >=0; i--)
#define ll long long
#define nline '\n'
#define prn cout << "NO" << nline
#define pry cout << "YES" << nline
#define vi vector<int>
#define vvi vector<vi>
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define inparr(v)   \
  for (auto &x : v) \
    cin >> x;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define mp make_pair
#define ff first
#define ss second
int n, m;

vi dist;
vector<vector<pii>> g; 
vi vis;

void dijkstra(int start_node) {
    priority_queue<pii> pq;
    pq.push({0, start_node});
    dist[start_node] = 0;

    while(!pq.empty()) {
        auto [_, top]= pq.top();
        pq.pop();

        if(vis[top]) continue;
        vis[top] = 1;

        for(auto [v, w] : g[top]) {
            if(dist[v] > dist[top] + w) {
                dist[v] = dist[top] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}
