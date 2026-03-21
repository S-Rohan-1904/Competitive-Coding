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

void zero_one_bfs(int start) {
    deque<int> dq;

    dist[start] = 0;
    dq.push_front(start);

    while (!dq.empty()) {
        int front = dq.front();
        dq.pop_front();

        if(vis[front]) continue;
        vis[front] = 1;

        for (auto &[v,w] : g[front]) {
            if (dist[v] > dist[front] + w) {
                dist[v] = dist[front] + w;
                if (w == 0) {
                    dq.push_front(v);
                } else {
                    dq.push_back(v);
                }
            }
        }
    }
}