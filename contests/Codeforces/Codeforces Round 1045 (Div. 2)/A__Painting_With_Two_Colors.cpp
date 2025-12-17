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

ll power(ll base, ll exp, ll mod) {
  ll res = 1;
  base %= mod;
  while (exp > 0) {
    if (exp % 2 == 1)
      res = (res * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return res;
}

ll modInverse(ll n, ll mod) { return power(n, mod - 2, mod); }

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  inparr(a);

  ll target = -1;
  vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

  for (int p : primes) {
    if (k % p != 0) {
      target = p;
      break;
    }
  }

  ll inv = modInverse(k, target);

  rep(i, 0, n) {
    ll target_rem = (target - a[i] % target) % target;
    a[i] += ((target_rem * inv) % target) * k;
  }

  rep(i, 0, n) { cout << a[i] << (i == n - 1 ? "" : " "); }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}