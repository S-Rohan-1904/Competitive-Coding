#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i < r; i++)
#define ll long long
#define endl '\n'
#define prn cout << "NO" << endl
#define pry cout << "YES" << endl
#define vi vector<int>
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define inparr(v)                                                              \
  for (auto &x : v)                                                            \
    cin >> x;
#define prarr(v)                                                               \
  for (auto &x : v)                                                            \
    cout << x << " ";                                                          \
  cout << endl;
#define pii pair<int, int>

void solve() {
  int n, q;
  cin >> n >> q;

  vi color(n + 1);
  rep(i, 1, n + 1) { cin >> color[i]; }

  vector<vector<pair<int, ll>>> adj(n + 1);
  ll total_cost = 0;

  rep(i, 0, n - 1) {
    int u, v;
    ll c;
    cin >> u >> v >> c;
    adj[u].eb(v, c);
    adj[v].eb(u, c);

    if (color[u] != color[v]) {
      total_cost += c;
    }
  }

  rep(i, 0, q) {
    int v, x;
    cin >> v >> x;

    int old_color = color[v];

    for (auto &edge : adj[v]) {
      int u = edge.first;
      ll c = edge.second;

      ll old_cost = (color[u] != old_color) ? c : 0;

      ll new_cost = (color[u] != x) ? c : 0;

      total_cost += new_cost - old_cost;
    }

    color[v] = x;
    cout << total_cost << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
