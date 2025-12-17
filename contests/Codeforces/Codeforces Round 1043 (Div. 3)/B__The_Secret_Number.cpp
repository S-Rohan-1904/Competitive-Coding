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
  ll n, k;
  cin >> n >> k;

  vector<ll> pow3(19);
  pow3[0] = 1;

  rep(i, 1, 19) { pow3[i] = 1LL * pow3[i - 1] * 3; }

  vector<ll> ops(19, 0);
  ll initialOp = 0;

  for (int i = 18; i >= 0 && n > 0; i--) {
    if (pow3[i] <= n) {
      ops[i] = n / pow3[i];
      n %= pow3[i];
      initialOp += ops[i];
    }
  }

  if (initialOp > k) {
    cout << -1 << endl;
    return;
  }

  ll remain = k - initialOp;
  if (remain % 2 == 1)
    remain--;

  for (int i = 18; i >= 1 && remain >= 2; i--) {
    while (ops[i] > 0 && remain >= 2) {
      ops[i]--;
      ops[i - 1] += 3;
      remain -= 2;
    }
  }

  ll ans = 0;
  rep(i, 0, 19) {
    if (ops[i] > 0) {
      ll cost = pow3[i] * 3;
      if (i > 0) {
        cost += i * pow3[i - 1];
      }
      ans += ops[i] * cost;
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
