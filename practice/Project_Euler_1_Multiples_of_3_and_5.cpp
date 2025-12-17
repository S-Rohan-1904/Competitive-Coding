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

const int MOD = 1000000007;

void solve()
{
    ll n;
    cin >> n;
    n--;

    ll temp1 = 3LL * (n / 3) * (n / 3 + 1) / 2;
    ll temp2 = 5LL * (n / 5) * (n / 5 + 1) / 2;
    ll temp3 = 15LL * (n / 15) * (n / 15 + 1) / 2;

    cout << temp1 + temp2 - temp3 << endl;
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
