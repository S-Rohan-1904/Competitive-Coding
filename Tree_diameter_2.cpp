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

vi dist;
vi par;
vvi g;

void dfs(int nn, int pp, int dd) {
    dist[nn] = dd;
    par[nn] = pp;

    for(auto v : g[nn]) {
        if(v != pp) {
            dfs(v, nn, dd + 1);
        }
    }
}
// counts nodes at depth = target
int countAtDepth(int nn, int pp, int dd, int target) {
    if(dd == target) return 1;


    int totalNodesAtDepth = 0;
    for(auto v : g[nn]) {
        if(v != pp) {
            totalNodesAtDepth += countAtDepth(v, nn, dd + 1, target);
        }
    }

    return totalNodesAtDepth;
}

void solve() {
    int n;
    cin>>n;
    dist.resize(n+1);
    par.resize(n+1);
    g.resize(n+1);
    int m = n-1;

    if(n==1) {
        cout<<1<<nline;
        return;
    }
    rep(i,0,m) {
        int a,b;
        cin>>a>>b;
        g[a].eb(b);
        g[b].eb(a);
    }

    dfs(1,0,0);
    int maxx = -1;
    // x and y are the endpoints of the diameter
    int x = -1;
    rep(i,1,n+1) {
        if(dist[i] > maxx) {
            maxx = dist[i];
            x = i;
        }
    }

    dfs(x,0,0);

    maxx = -1;
    int y = -1;
    rep(i,1,n+1) {
        if(dist[i] > maxx) {
            maxx = dist[i];
            y = i;
        }
    }

    // maxx is the diameter
    // up is the amount of steps to be taken to find the centre from y
    int up = maxx/2;
    int ans = 0;
    if(maxx%2 == 0) {
        int c = y;
        while(up--) {
            c = par[c];
        }
        int depth = maxx/2;

        int sum = 0;

        // simple combinatorics to find the ans using number of nodes in child branch at depth d/2 from centre
        for(auto v : g[c]) {
            int cnt = countAtDepth(v,c,1,depth);
            pr(cnt);
            ans += sum * cnt;
            sum += cnt;
        }
        
    } else {
        int c1 = y;
        while(up--) {
            c1 = par[c1];
        }
        int c2 = par[c1];

        int cnt1 = countAtDepth(c1, c2, 0, maxx/2);
        int cnt2 = countAtDepth(c2, c1, 0, maxx/2);

        ans = cnt1 * cnt2;
        
    }

    cout<<ans<<nline;
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
