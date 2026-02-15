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

const int MOD = 1000000007;

#define INF 1e9

using state = pii;

vector<vector<char>> g;
vvi vis;
vvi dist;
int n,m;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

bool is_valid(int x, int y) {
  if( x>=0 && x<n && y>=0 && y<m) return 1;
  return 0;
}

vector<state> children(state node) {
  vector<state> childs;
  rep(i,0,4) {
    int nx = node.ff + dx[i];
    int ny = node.ss + dy[i];

    if(is_valid(nx,ny)) {
      childs.eb(nx,ny);
    }
  } 
  return childs;
}

void bfs(state st) {
  queue<state> q;

  q.push(st);
  dist[st.ff][st.ss] = 0;


  while(!q.empty()) {
    state node = q.front();
    q.pop();

    if(vis[node.ff][node.ss]) continue;

    vis[node.ff][node.ss] = 1;

    for(auto v : children(node)) {
      if(!vis[v.ff][v.ss]) {
        q.push(v);
        dist[v.ff][v.ss] = dist[node.ff][node.ss] + 1;
      } 
    }

  }
}

void solve()
{
  cin>>n>>m;

  g.assign(n, vector<char>(m));
  vis.assign(n, vi(m,0));
  dist.assign(n, vi(m,INF));

  state st,en;

  rep(i,0,n) {
    string str;
    cin>>str;
    rep(j,0,m) {
      g[i][j] = str[j];
      if(g[i][j] == 'A') st = {i,j};
      else if(g[i][j] == 'B') en = {i,j};
    }
  }

  bfs(st);

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
