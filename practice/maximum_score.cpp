#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i < r; i++)
#define rrep(i, r, l) for (int i = r-1; i >=0; i--)
#define ll long long
#define nline '\n'
#define prn cout << "NO" << nline
#define pry cout << "YES" << nline
#define vi vector<int>
#define vvi vector<vi>
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define inparr(v)   \
  for (auto &x : v) \
    cin >> x;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vvpii vector<vector<pii>>
#define mp make_pair
#define ff first
#define ss second
#define float long double

// #define int long long

//---- Debugger ---- //
#ifdef LOCAL
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<nline;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<nline;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
#else
#define pr(...)
#endif
//----------------- //

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;
// dp(i,j) -> maximum score ending at (i,j)
vvi g;
int n, m, k;

// the path that gives the maximum sum to a top cell may not be divisible, while a different path to that same cell (with a smaller sum) could be divisible. Hence just maximum sum is not sufficient


void solve() {
    cin>>n>>m>>k;

    g.assign(n, vi(m));

    rep(i,0,n) {
        string s;
        cin>>s;
        rep(j,0,m) {
            g[i][j] = s[j] - '0';
        }
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1e9)));
    for(int i = 0; i < m; i++) {
        dp[n-1][i][g[n-1][i] % k] = g[n-1][i];
    }

    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            for(int r = 0; r < k; r++) {
                if(j-1 >= 0)  dp[i][j][(r+g[i][j])%k] = max(dp[i][j][(r+g[i][j])%k], dp[i+1][j-1][r] + g[i][j]);
                if(j+1 < m)  dp[i][j][(r+g[i][j])%k] = max(dp[i][j][(r+g[i][j])%k], dp[i+1][j+1][r] + g[i][j]);
            }
        }
    }

    int ans = -1e9;
    for(int j = 0; j < m; j++) {
        pr(j, dp[0][j][0]);
        ans = max(ans, dp[0][j][0]);
    }

    if(ans < 0) cout << -1 << nline;
    else cout << ans << nline;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    solve();
}
