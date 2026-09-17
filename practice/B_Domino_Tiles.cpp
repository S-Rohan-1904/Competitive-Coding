#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i < r; i++)
#define rrep(i, r, l) for (int i = r; i >=0; i--)
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
/*
the two neighboring tiles si and si+1 form a domino of weight (si + si+1). 
Note that two consecutive dominoes share exactly one tile. 
The completed row is valid if every two consecutive dominoes have different weights

there are 8 cases with 0, 1, ?
0 0 0
0 0 1

basically the alternative elements must be different

because the middle element is common
si + si+1 = si+1 + si+2
which gives si = si+2

but the even and odd indices condition is not independent?

no it is independent

01234
0?1??

level : 0, last : 0, ans : 0
level : 4, last : 1, ans : 1
level : 2, last : 0, ans : 1
level : 0, last : 1, ans : 1
level : 3, last : 1, ans : 1
level : 1, last : 0, ans : 1
level : 3, last : 0, ans : 1
level : 1, last : 1, ans : 1

now i need to check 

*/

int rec(int level, int laste, int lasto, string & s) {
    int n = s.size();
    if(level + 1 >= n) {
        pr("final", level, laste, lasto);
        if(s[level] == '?') return 1;
        else if(s[level] - '0' != laste) return 1;
        return 0;
    }
    int ans = 0;
    int ec = s[level] - '0';
    int oc = s[level + 1] - '0';
    if(s[level] == '?' && s[level + 1] == '?') {
        ans = rec(level + 2, !laste, !lasto, s);
    } else if(s[level] == '?') {
        if(oc != lasto)
            ans = rec(level + 2, !laste, oc, s);
    } else if(s[level + 1] == '?') {
        if(ec != laste)
            ans = rec(level + 2, ec, !lasto, s);
    } else {
        if(ec != laste && oc != lasto) 
            ans = rec(level + 2, ec, oc, s);
    }
    pr(level, laste, lasto, ans);
    return ans;
}
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;    


    cout << rec(0, 0, 0, s) + rec(0, 0, 1, s) + rec(0, 1, 0, s) + rec(0, 1, 1, s) << nline;
    pr(nline);
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
