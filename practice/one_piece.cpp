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

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int n,m;
vvi g;
vvi dist;
vvi vis;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int color[] = {1, 2, 3, 4};
/*
1->R
2->L
3->D
4->U
*/
using state = pii;
void bfs01(state st) {
    deque<state> dq;
    dq.push_front(st);
    dist[st.ff][st.ss] = 0;

    while (!dq.empty())
    {
        state front = dq.front();
        dq.pop_front();

        if(vis[front.ff][front.ss]) continue;
        vis[front.ff][front.ss] = 1;

        rep(i,0,4) {
            int nx = front.ff + dx[i];
            int ny = front.ss + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m) {
                int cost = 1;
                if(color[i] == g[front.ff][front.ss]) cost = 0;
                if(dist[nx][ny] > dist[front.ff][front.ss] + cost) {
                    dist[nx][ny] = dist[front.ff][front.ss] + cost;
                    if(cost == 0) dq.push_front({nx,ny});
                    else dq.push_back({nx,ny});
                }
            }
        }
    }
    

}

void solve()
{
    cin>>n>>m;
    g.resize(n, vi(m));
    dist.assign(n, vi(m, INF));
    vis.assign(n, vi(m, 0));

    rep(i,0,n) {
        rep(j,0,m) {
            cin>>g[i][j];
        }
    }

    bfs01({0,0});

    // rep(i,0,n) {
    //     rep(j,0,m) {
    //         cout<< dist[i][j]<<" ";
    //     }
    //     cout<<nline;
    // }

    cout << dist[n-1][m-1]<<nline;
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
