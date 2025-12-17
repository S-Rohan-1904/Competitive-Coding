#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i < r; i++)
#define ll long long
#define endl '\n'
#define prn cout << "NO" << endl
#define pry cout << "YES" << endl
#define vi vector<int>
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
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> reqs(n);
  rep(i, 0, n) { cin >> reqs[i].first >> reqs[i].second; }

  ll ans = 0;
  ll current_time = 0;
  ll current_side = 0;

  for (const auto &req : reqs) {
    ll next_time = req.first;
    ll next_side = req.second;
    ll diff = next_time - current_time;

    if (abs(current_side - next_side) == diff % 2) {
      ans += diff;
    } else {
      ans += diff - 1;
    }

    current_time = next_time;
    current_side = next_side;
  }

  ans += (m - current_time);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}
