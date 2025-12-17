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

const int N = 2 * pow(10, 5) + 1;
void solve() {
  int n;
  cin >> n;
  vi a(n);
  inparr(a);

  vi hash(N + 1);
  rep(i, 0, n) { hash[a[i]]++; }

  vector<pii> intitial;

  rep(i, 1, N) {
    if (hash[i] >= i)
      intitial.eb(i, hash[i]);
  }

  sort(all(intitial), [](pair<int, int> a, pair<int, int> b) {
    return a.second / a.first > b.second / b.first;
  });

  int ans = 0;
  for (auto &p : intitial) {
    vi temp(hash);
    vi taken(N + 1);
    int cnt = 0;
    bool found = false;
    rep(i, 0, n) {
      if (!found && a[i] == p.ff)
        found = true;
      if (found) {
        found = false;
        taken[i]
      } else {
      }
    }
    ans = max(ans, cnt);
  }
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
