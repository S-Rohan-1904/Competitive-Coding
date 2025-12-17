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

void solve()
{
  int n, q;
  cin >> n >> q;
  string str;
  cin >> str;

  while (q--)
  {
    ll a;
    cin >> a;

    ll ans = 0;
    int curr = 0;

    bool found_b = false;

    rep(i, 0, n)
    {
      if (str[i] == 'B')
      {
        found_b = true;
        break;
      }
    }
    if (!found_b)
    {

      cout << a << endl;
      continue;
    }

    while (a > 0)
    {
      ans++;
      if (str[curr] == 'A')
        a -= 1;
      else
        a /= 2;

      if (a == 0)
        break;

      curr = (curr + 1) % n;
    }
    cout << ans << endl;
  }
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
