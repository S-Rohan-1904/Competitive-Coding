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
  int n;
  cin >> n;
  vi x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];
  int X = *max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end());
  int Y = *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end());
  cout << (max(X, Y) + 1) / 2 << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
