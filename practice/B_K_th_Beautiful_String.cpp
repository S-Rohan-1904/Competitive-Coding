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

long long der[1000001];

void compute_derangements(int N, int mod = MOD)
{
    der[1] = 0; // !1 = 0
    der[2] = 1; // !2 = 1
    for (int i = 3; i <= N; i++)
    {
        der[i] = (1LL * (i - 1) * (der[i - 1] + der[i - 2])) % mod;
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << der[n] << endl;
}

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    compute_derangements(1000001);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
