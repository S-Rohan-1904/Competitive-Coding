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
const int INF = 1e18;
using state = pii;

int n,m;
int st_node, en_node, init_capcity;
vector<vector<state>> g;
vvi dist;
vvi vis;
vi c;

void dijkstra(pii st) {
    // prioirty queue -> {dist, {city, fuel}}
    priority_queue<pair<int, pii>> pq;
    pq.push(mp(-0, st));
    dist[st.ff][st.ss] = 0;

    while(!pq.empty()) {
        auto top = pq.top();
        int top_node = top.ss.ff;
        int top_fuel = top.ss.ss;
        pq.pop();

        if(vis[top_node][top_fuel]) continue;
        vis[top_node][top_fuel] = 1;

        for(auto [v, p] : g[top_node]) {
            // moving to the city only burns fuel(we are not buying fuel in this transition), and we are minimizing the cost.
            if(top_fuel >= p && dist[v][top_fuel - p] > dist[top_node][top_fuel] + 0) {
                dist[v][top_fuel - p] = dist[top_node][top_fuel] + 0;
                pq.push(mp(-dist[v][top_fuel - p], mp(v, top_fuel - p)));
            }
        } 
        // refuelling 1 litre in the current city
        if(top_fuel < init_capcity && dist[top_node][top_fuel+1] > dist[top_node][top_fuel] + c[top_node]) {
            dist[top_node][top_fuel+1] = dist[top_node][top_fuel] + c[top_node];
            pq.push(mp(-dist[top_node][top_fuel+1], mp(top_node, top_fuel + 1)));
        }
    }

}
void solve()
{
    cin>>n>>m;
    g.resize(n+1);
    c.resize(n+1);
    
    rep(i,0,m) {
        int u, v, w;
        cin>>u>>v>>w;
        g[u].eb(v,w);
        g[v].eb(u,w);
    }
    rep(i,1,n+1) {
        cin>>c[i];
    }
    cin>>st_node>>en_node>>init_capcity;
    dist.assign(n+1, vector<int>(init_capcity + 1, INF));
    vis.assign(n+1, vector<int>(init_capcity + 1, 0));

    dijkstra({st_node, 0});
    // it is always optimal to refuel just enough
    cout<<dist[en_node][0]<<nline;
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
