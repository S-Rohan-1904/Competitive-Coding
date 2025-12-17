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
#define int long long

const int MOD = 1000000007;

struct mint
{
    static int mod;
    int x;

    mint() : x(0) {}
    mint(ll _x)
    {
        _x %= mod;
        if (_x < 0)
            _x += mod;
        x = (int)_x;
    }

    mint &operator+=(const mint &a)
    {
        x += a.x;
        if (x >= mod)
            x -= mod;
        return *this;
    }
    mint &operator-=(const mint &a)
    {
        x += mod - a.x;
        if (x >= mod)
            x -= mod;
        return *this;
    }
    mint &operator*=(const mint &a)
    {
        x = (int)((ll)x * a.x % mod);
        return *this;
    }
    mint pow(ll t) const
    {
        mint res = 1, cur = *this;
        while (t)
        {
            if (t & 1)
                res *= cur;
            cur *= cur;
            t >>= 1;
        }
        return res;
    }
    mint inv() const
    {
        return pow(mod - 2);
    }
    mint &operator/=(const mint &a)
    {
        return *this *= a.inv();
    }
    friend mint operator+(mint a, const mint &b) { return a += b; }
    friend mint operator-(mint a, const mint &b) { return a -= b; }
    friend mint operator*(mint a, const mint &b) { return a *= b; }
    friend mint operator/(mint a, const mint &b) { return a /= b; }
    friend ostream &operator<<(ostream &os, const mint &m) { return os << m.x; }
    friend istream &operator>>(istream &is, mint &m)
    {
        ll t;
        is >> t;
        m = mint(t);
        return is;
    }
};

int mint::mod = MOD;

void solve()
{
    int n, m;
    cin >> n >> m;

    int a = n / m;
    int r = n % m;

    int kmin = (m - r) * a * (a - 1) / 2 + r * (a + 1) * a / 2;
    int kmax = (n - m + 1) * (n - m) / 2;

    cout << kmin << " " << kmax << endl;
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
