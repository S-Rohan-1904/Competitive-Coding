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
#define inparr(v)   \
  for (auto &x : v) \
    cin >> x;
#define prarr(v)      \
  for (auto &x : v)   \
    cout << x << " "; \
  cout << endl;
#define pii pair<int, int>

const int MOD = 1000000007;

vector<ll> divisors(ll x)
{
  vector<ll> ans;
  for (ll i = 1; i * i <= x; i++)
  {
    if (x % i == 0)
    {
      ans.push_back(i);
      if (i * i != x)
        ans.push_back(x / i);
    }
  }
  return ans;
}

void solve()
{
  ll n;
  cin >> n;
  vector<ll> ans = divisors(n);
  sort(all(ans));
  rep(i, 0, ans.size())
  {
    cout << ans[i] << endl;
  }
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}
