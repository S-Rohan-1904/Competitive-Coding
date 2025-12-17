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
#define inparr(v)     \
    for (auto &x : v) \
        cin >> x;
#define prarr(v)          \
    for (auto &x : v)     \
        cout << x << " "; \
    cout << endl;
#define pii pair<int, int>

const int MOD = 1e9;

const int MAXN = 1000001;

ll fact[MAXN];
ll invfact[MAXN];

ll binpow(ll a, ll b)
{
    a %= MOD;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll inverse(ll n)
{
    return binpow(n, MOD - 2);
}

void precompute()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invfact[MAXN - 1] = inverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--)
    {
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }
}

ll ncr(int n, int r)
{
    if (r < 0 || r > n)
    {
        return 0;
    }
    ll num = fact[n];
    ll den = (invfact[n - r] * invfact[r]) % MOD;
    return (num * den) % MOD;
}

void solve()
{
    ll n;
    cin >> n;

    rep(i, 0, n + 1)
    {
        cout << ncr(n, i) << " ";
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    precompute();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
