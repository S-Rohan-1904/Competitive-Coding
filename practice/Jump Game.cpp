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
const int INF = 1e18 + 1;

vvpii g;
vi vis;
vi dist;

void dijkstra(int src) {
    priority_queue<pii> pq;
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int top_el = top.ss;

        if(vis[top_el]) continue;
        vis[top_el] = 1;
        
        for(auto v : g[top_el]) {
            int w = v.ss;
            int node = v.ff;
            if(dist[node] > dist[top_el] + w) {
                dist[node] = dist[top_el] + w;
                pq.push({-dist[node], node});
            }
        }
    }

}

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    vi arr(n+1);
    rep(i,1,n+1) {
        cin>>arr[i];
    }

    int src;
    cin>>src;

    map<int,int> hsh;

    rep(i,1,n+1) hsh[arr[i]]++;

    int m = n + hsh.size() + 1;
    g.resize(m);
    vis.assign(m, 0);
    dist.assign(m, INF);


    rep(i,1,n) {
        g[i].eb(mp(i+1, b));
        g[i+1].eb(mp(i, b));
    }
    rep(i,1,n+1) {
        int el = arr[i];
        g[n+el].eb(mp(i, a));
        g[i].eb(mp(n+el, 0));
    }

    pr(g);

    dijkstra(src);

    rep(i,1,n+1) {
        cout<<dist[i]<<" ";
    }
    cout<<nline;
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
//   cin >> t;
  while (t--)
    solve();
}
