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

const int N = 1000100;
int spf[N];

void sieve()
{
  for (int i = 2; i < N; i++)
  {
    spf[i] = i;
  }
  for (int i = 2; i < N; i++)
  {
    if (spf[i] == i)
    {
      for (int j = 2 * i; j < N; j += i)
      {
        if (spf[j] == j)
        {
          spf[j] = i;
        }
      }
    }
  }
}

int freq[1000100];

int ans = 0;

void process(int x)
{
  int red = 1;
  int cred = 1;
  while (x != 1)
  {
    int i = spf[x];
    int ipow = 0;
    while (x % i == 0)
    {
      ipow++;
      x /= i;
    }

    ipow %= 3;
    if (ipow == 1)
    {
      red *= i;
      cred *= i * i;
    }
    else if (ipow == 2)
    {
      red *= i * i;
      cred *= i;
    }
  }
  if (cred <= 1000000)
    ans += freq[cred];
  freq[red]++;
}

void solve()
{
  int n;
  cin >> n;

  vi a(n);
  inparr(a);
  rep(j, 0, n)
  {
    int x = a[j];
    process(x);
  }
  cout << ans << endl;
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  sieve();
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}
