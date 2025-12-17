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
const int temp = 1000000001;

void solve()
{
    int n;
    cin >> n;
    vi beauty(n);
    inparr(beauty);

    sort(all(beauty));
    if (beauty[0] == beauty[n - 1])
        cout << beauty[n - 1] - beauty[0] << " " << 1LL * n * (n - 1) / 2 << endl;
    else
    {
        int minn = beauty[0];
        int maxx = beauty[n - 1];
        int cnt1 = 0, cnt2 = 0;
        rep(i, 0, n)
        {
            if (beauty[i] == minn)
                cnt1++;
            else if (beauty[i] == maxx)
                cnt2++;
        }
        cout << maxx - minn << " " << 1LL * cnt1 * cnt2 << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}
