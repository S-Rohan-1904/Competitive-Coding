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

string s, t;
int n,m;
int dp[1001][1001];
int rec(int i, int j) {
    if(i > n || j > m) return 1e9;
    if(i == n && j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = min({1+rec(i+1,j), 1 + rec(i,j+1), 1 + rec(i+1, j+1)});

    if(s[i] == t[j]) ans = min(ans, rec(i+1, j+1));

    return dp[i][j] = ans;
}

// delete -> rec(i+1, j)
// insert -> rec(i, j+1)
// replace -> rec(i+1, j+1)

void generate(int i, int j) {
    int ans = rec(i,j);
    if(s[i] == t[j] && ans == rec(i+1, j+1)) generate(i+1, j+1);
    else {
        if(ans == 1 + rec(i+1,j)) {
            cout << "DELETE " << j + 1<< nline;
            generate(i+1, j);
        } else if(ans == 1 + rec(i,j + 1)) {
            cout << "INSERT " << j + 1<< " " << t[j] <<nline;
            generate(i, j+1);
        } else if(ans == 1 + rec(i+1,j + 1)) {
            cout << "REPLACE " << j + 1<< " " << t[j] << nline;
            generate(i+1, j+1);
        }
    }
}
// A C C E P T E D
// 1 2 3 4 5 6 7 8 9 
// W R O N G A N S W E R
// W R O N G A N S W E R

void solve() {
    cin>>s>>t;
    n = s.size();
    m = t.size();

    memset(dp, -1, sizeof(dp));

    cout << rec(0,0) << nline; 

    generate(0, 0);

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    solve();
}
