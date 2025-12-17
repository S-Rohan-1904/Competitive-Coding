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
    int n, k;
    cin >> n >> k;

    string str;
    cin >> str;

    vi hash(26);

    rep(i, 0, k)
    {
        char ch;
        cin >> ch;

        hash[ch - 'a'] = 1;
    }
    vi lengths;
    int curr = 0;
    rep(i, 0, n)
    {

        if (hash[str[i] - 'a'] == 0)
        {
            if (curr != 0)
                lengths.eb(curr);
            curr = 0;
        }
        else
            curr++;
    }
    lengths.eb(curr);
    ll ans = 0;
    for (auto &el : lengths)
    {
        ans += 1LL * el * (el + 1) / 2;
    }
    cout << ans << endl;
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
