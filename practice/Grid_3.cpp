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

void solve() {
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int>> grid(n, vector<int>(m));

    rep(i,0,n) {
        rep(j,0,m) {
            cin>>grid[i][j];
        }
    }
    // 1,2,3,4
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // dp(i,j,k)->ending at i,j with down
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

                if(grid[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }

                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                
                for(int p = 0; p <= k; p++) {
                    if(j-p >= 0 && i) {
                        if(grid[i-1][j-p]) break;
                        dp[i][j] = (dp[i][j]%MOD + dp[i-1][j-p]%MOD)%MOD;
                    }
                }
        }
    }
    int ans = 0;
    for (int p = 0; p <= k; p++) {
        if (m - 1 - p < 0) break;
        
        // CRITICAL FIX: If a cell in the final stretch is blocked, stop adding.
        if (grid[n - 1][m - 1 - p] == 1) break; 
        
        ans = (ans + dp[n - 1][m - 1 - p]) % MOD;
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout <<nline;
    // }
    cout << ans<< nline;
    
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
