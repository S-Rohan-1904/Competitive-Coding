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
// 1 -> 0
// 2 -> 1
// 3 -> 1
// 4 -> 2
// 5 -> 2
// 6 -> 3
void solve() {
  int n;
  cin >> n;
  vi a(n);
  inparr(a);
  vi odds;
  rep(i, 0, n) {
    if (a[i] % 2 != 0)
      odds.eb(a[i]);
  }
  sort(all(odds));

  ll ans = 0;
  if (odds.size() == 0) {
    cout << 0 << endl;
    return;
  } else if (odds.size() == 1) {
    rep(i, 0, n) ans += a[i];
  } else {
    int remove_cnt = odds.size() / 2;
    rep(i, 0, n) ans += a[i];
    rep(i, 0, remove_cnt) ans -= odds[i];
  }
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
