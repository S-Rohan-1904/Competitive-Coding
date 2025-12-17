#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, l, r) for (int i = l; i < r; i++)
#define ll long long
#define endl '\n'
#define prn cout << "NO" << endl
#define pry cout << "YES" << endl
#define vi vector<int>
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define inparr(v)   \
  for (auto &x : v) \
    cin >> x;
#define prarr(v)      \
  for (auto &x : v)   \
    cout << x << " "; \
  cout << endl;
#define pii pair<int, int>

const int MOD = 1000000007;

bool is_prime(ll x)
{
  if (x < 2)
    return false;
  for (ll i = 2; i * i <= x; i++)
  {
    if (x % i == 0)
      return false;
  }
  return true;
}

bool isPerfectSquare(ll n)
{
  if (n <= 1)
    return false;

  ll left = 1, right = 10000000;

  while (left <= right)
  {

    ll mid = left + (right - left) / 2;

    ll square = mid * mid;

    if (square == n)
    {

      return is_prime(mid);
    }

    else if (square < n)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return false;
}

void solve()
{
  ll x;
  cin >> x;

  if (isPerfectSquare(x))
    pry;
  else
    prn;
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}