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
#define ff first
#define ss second
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<ll> apos;

  rep(i, 0, 2 * n) {
    if (s[i] == 'A') {
      apos.push_back(i);
    }
  }

  ll cost1 = 0;
  rep(i, 0, n) { cost1 += abs(apos[i] - (1LL * 2 * i)); }

  ll cost2 = 0;
  rep(i, 0, n) { cost2 += abs(apos[i] - (1LL * 2 * i + 1)); }

  cout << min(cost1, cost2) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
