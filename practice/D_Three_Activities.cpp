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
pick largest from a,b,c then pick largest from a,b then from a
if there are multiple max's pick the one with minimum opportunity cost
*/


void solve() {
    int n;
    cin>>n;
    vi a(n), b(n), c(n);
    inparr(a);
    inparr(b);
    inparr(c);

    int maxa = *max_element(all(a));
    int maxb = *max_element(all(b));
    int maxc = *max_element(all(c));
    int ans = 0;
    if(maxb == max({maxa,maxb,maxc})) {
        swap(a,b);
    } else if(maxc == max({maxa,maxb,maxc})) {
        swap(a,c);
    }
    if(maxa == max({maxa,maxb,maxc})) {
        int temp = INT_MAX;
        int minidx;
        rep(i,0,n) {
            if(a[i] == maxa && max(b[i], c[i]) < temp) {
                temp = max(b[i], c[i]);
                minidx = i;
            }
            
        }

        ans += maxa;
        pr(maxa);
        b.erase(b.begin() + minidx);
        c.erase(c.begin() + minidx);
        
        maxb = *max_element(all(b));
        maxc = *max_element(all(c));
        
        if(maxc > maxb) {
            swap(b, c);
        }  
        
        ans+=maxb;
        pr(maxb);
        n = b.size();
        rep(i,0,n) {
            if(b[i] == maxb && c[i] < temp) {
                temp = c[i];
                minidx = i;
            }
        }
        
        c.erase(c.begin() + minidx);
        maxc = *max_element(all(c));
        ans += maxc;
        pr(maxc);
        
    }
    pr(nline);
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
