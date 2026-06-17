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
// dp(i,j,k) -> returns number of paths from (i,j) to (n-1, m-1)

int n, m, k;

vvi g;
int dp[201][201][401];
int rec(int i, int j, int k) {
    if(k < 0) return 0;
    if( i >= n || j >= m) return 0;
    if(i == n-1 && j == m-1) return 1;
    if(dp[i][j][k] != -1) return dp[i][j][k];

    int ans = 0;
    
    if(i + 1 < n && g[i + 1][j] == 0) ans = (ans + rec(i+1, j, k)) % MOD;
    else ans = (ans + rec(i+1, j, k-1)) % MOD;

    if(j + 1 < m && g[i][j + 1] == 0) ans = (ans + rec(i, j + 1, k)) % MOD;
    else ans = (ans + rec(i, j + 1, k-1)) % MOD;

    return dp[i][j][k] = ans;
}

void solve() {
    cin>>n>>m>>k;
    g.assign(n, vi(m, 0));

    rep(i,0,n) {
        rep(j,0,m) {
            cin >> g[i][j]; 
        }
    }
    rep(i,0,n) {
        rep(j,0,m) {
            rep(t, 0, k+1) {
                dp[i][j][t] = -1;
            }
        }
    }
    int starting_k = k;
    if (g[0][0] == 1) {
        starting_k--;
    }

    int ans = rec(0, 0, starting_k);
    cout << ans << nline;

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
