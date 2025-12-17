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
#define vvi vector<vi>

void solve() {
  int n;
  cin >> n;
  vvi points(n, vi(3));

  rep(i, 0, n) {
    cin >> points[i][0] >> points[i][1];
    points[i][2] = i + 1;
  }

  sort(all(points), [](const vi &a, const vi &b) {
    if (a[0] == b[0])
      return a[1] < b[1];
    else
      return a[0] < b[0];
  });

  vvi left, right;

  rep(i, 0, n / 2) { left.pb(points[i]); }
  rep(i, n / 2, n) { right.pb(points[i]); }

  sort(all(left), [](const vi &a, const vi &b) { return a[1] < b[1]; });
  sort(all(right), [](const vi &a, const vi &b) { return a[1] < b[1]; });

  rep(i, 0, n / 2) {
    cout << left[i][2] << " " << right[n / 2 - i - 1][2] << endl;
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
