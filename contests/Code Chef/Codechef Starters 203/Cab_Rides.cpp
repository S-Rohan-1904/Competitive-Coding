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

  vi w(n * (n - 1) / 2);
  inparr(w);

  priority_queue<int> pq;
  rep(i, 0, n) { pq.push(1); }
  ll slots = 0;

  ll ans = 0;
  rep(i, 0, n * (n - 1) / 2) {
    if (slots > 0)
      --slots;
    else {
      ans += w[i];
      int temp1 = pq.top();
      pq.pop();
      int temp2 = pq.top();
      pq.pop();
      pq.push(temp1 + temp2);
      slots += (ll)temp1 * temp2 - 1;
    }
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
