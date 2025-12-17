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

vi sieve(int n)
{
    vi primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = 1LL * i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}

vi segmented_sieve(int L, int R)
{
    vi base_primes = sieve(ceil(sqrt(R)));

    vector<bool> is_prime(R - L + 1, true);
    if (L == 1)
        is_prime[0] = false;

    for (auto prime : base_primes)
    {
        int ceil_l_by_p = (L + prime - 1) / prime;
        int cur_mul = prime * ceil_l_by_p;
        cur_mul = max(prime * prime, cur_mul);

        while (cur_mul <= R)
        {
            is_prime[cur_mul - L] = false;
            cur_mul += prime;
        }
    }

    vi primes_l_to_r;
    for (int i = 0; i < R - L + 1; i++)
    {
        if (is_prime[i])
        {
            primes_l_to_r.push_back(i + L);
        }
    }

    return primes_l_to_r;
}

void solve()
{
    int l, r;
    cin >> l >> r;
    vi ans = segmented_sieve(l, r);
    cout << ans.size() << endl;
    prarr(ans);
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
