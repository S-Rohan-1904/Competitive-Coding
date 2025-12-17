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
  int a, b;
  cin >> a >> b;

  cout << 50 * b - 30 * a << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  // cin >> t;
  // while (t--)
  solve();
}

bool isPrime(long long x) {
  if (x <= 1)
    return false;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0)
      return false;
  }
  return true;
}

vector<long long> divisors(long long x) {
  vector<long long> ans;
  for (long long i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      ans.pb(i);
      if (i * i != x)
        ans.pb(x / i);
    }
  }
  return ans;
}

vector<pair<ll, ll>> factors(ll x) {
  vector<pair<ll, ll>> ans;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      int cnt = 0;
      while (x % i == 0) {
        cnt++;
        x /= i;
      }
      ans.pb({i, cnt});
    }
  }
  if (x > 1)
    ans.pb({x, 1});
  return ans;
}