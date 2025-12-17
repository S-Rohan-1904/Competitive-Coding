#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i < r; i++)
#define ll long long
#define endl "\n"
#define prn cout << "nO" << endl
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
  int n, m;
  cin >> n >> m;
  string ans = "";
  if (n == 0) {
    rep(i, 0, m - 2) ans += "><";
    ans += ">=>";
    // rep(i, 1, m) ans = ans + "=>";
  } else if (m == 0) {
    rep(i, 0, n - 2) ans += "<<";
    ans += "<=<";
    // rep(i, 1, n) ans = ans + "=<";
  } else {
    rep(i, 0, n) ans += "<<";
    ans += ">";
    rep(i, 0, m - 1) ans += "<>";
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
