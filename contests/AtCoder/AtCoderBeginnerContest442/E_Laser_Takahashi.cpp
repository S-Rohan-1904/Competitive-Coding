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
#define mp make_pair
#define ff first
#define ss second

#define int long long

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

struct Point { int x, y; };

bool is_upper(const Point& p) {
    return p.y > 0 || (p.y == 0 && p.x > 0);
}

int cross_product(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

bool same_dir(const Point& a, const Point& b) {
    if (is_upper(a) != is_upper(b)) return false;
    return cross_product(a, b) == 0;
}

void solve() {
    int n; cin >> n;
    int q; cin >> q;

    vector<Point> pts(n);
    rep(i, 0,n) cin >> pts[i].x >> pts[i].y;

    vector<int> p(n);
    iota(all(p), 0);

    sort(all(p), [&](int i, int j) {
        bool upA = is_upper(pts[i]);
        bool upB = is_upper(pts[j]);
        if (upA != upB) return upA;
        return cross_product(pts[i], pts[j]) > 0;
    });

    vector<int> pos(n);
    rep(i, 0,n) pos[p[i]] = i;

    vector<int> L(n), R(n);
    
    rep(i, 0,n) {
        if (i > 0 && same_dir(pts[p[i]], pts[p[i-1]])) L[i] = L[i-1];
        else L[i] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i < n - 1 && same_dir(pts[p[i]], pts[p[i+1]])) R[i] = R[i+1];
        else R[i] = i;
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        --u; --v; 

        int idxA = pos[u];
        int idxB = pos[v];

        int s = R[idxA];
        int e = L[idxB]; 

        if (same_dir(pts[u], pts[v])) {
            cout << (R[idxA] - L[idxA] + 1) << nline;
        } else if (idxA > idxB) {
            cout << (s - e + 1) << nline;
        } else {
            cout << (s + 1) + (n - e) << nline;
        }
    }
}



signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin>>t;
  while (t--)
    solve();
}