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

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

vvi g;
vi dist;
vi par;

void dfs(int nn, int pp, int dd) {
    dist[nn] = dd;
    par[nn] = pp;

    for(auto v : g[nn]) {
        if(v!= pp) {
            dfs(v,nn, dd+ 1);
        }
    }
}


void solve() {
    int n;
    cin>>n;

    g.resize(n+1);
    dist.resize(n+1);
    par.resize(n+1);

    int m = n-1;
    rep(i,0,m) {
        int u, v;
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }

    dfs(1,0,0);

    int x = -1;
    int maxx = -1;
    
    rep(i,1,n+1) {
        if(dist[i] > maxx) {
            x = i;
            maxx = dist[i];
        }
    }
    
    dfs(x,0,0);
    int y = -1;
    maxx = -1;

    rep(i,1,n+1) {
        if(dist[i] > maxx) {
            y = i;
            maxx = dist[i];
        }
    }

    int up = maxx/2;

    while(up--) {
        y = par[y];
    }

    dfs(y,0,0);


    map<int,set<int>> levels;

    rep(i,1,n+1) {
        levels[dist[i]].emplace(i);
    }

    vector<int> colors(n+1, 0);

    // 0 -> black
    // 1 -> white

    int q;
    cin>>q;
    while(q--) {
        int x;
        cin>>x;
        if(colors[x] == 1) {
            levels[dist[x]].emplace(x);
            colors[x] = 2;
        } else {
            colors[x] = 1;
            levels[dist[x]].erase(x);
            
            if(levels[dist[x]].size() == 0) {
                levels.erase(dist[x]);
            }
            
        }

        set<int> maxLevel = levels.rbegin() -> second;

        if(maxLevel.size() >= 2) cout<< 2 * (levels.rbegin() -> first) << nline;
        else {
            cout << (levels.rbegin() -> first) +  (prev(prev(levels.end())) -> first)<<nline;
        }


    }

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
