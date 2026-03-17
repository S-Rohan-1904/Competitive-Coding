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


using state = pii;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;
int n,m;
vector<vector<char>> g;
vector<state> monsters;
vector<state> exits;
vvi dm;
vvi dp;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
state st,en;

vector<state> child_m(state front) {
    vector<state> child_m;
    rep(i,0,4) {
        int nx = front.ff + dx[i];
        int ny = front.ss + dy[i];
        if(nx <n && nx>=0 && ny<m && ny >=0 && g[nx][ny] != '#' && dm[nx][ny] == INF) {
            child_m.eb(nx,ny);
        }
    }
    return child_m;
}
vector<state> child_p(state front) {
    vector<state> child_p;
    rep(i,0,4) {
        int nx = front.ff + dx[i];
        int ny = front.ss + dy[i];
        if(nx <n && nx>=0 && ny<m && ny >=0 && g[nx][ny] != '#' && g[nx][ny] != 'M' && dp[nx][ny] == INF) {
            child_p.eb(nx,ny);
        }
    }
    return child_p;
}

void bfs_mon() {
    queue<state> q;
    for(auto monster: monsters) {
        q.push(monster);
        dm[monster.ff][monster.ss] = 0;
    }

    pr(monsters);
    while(!q.empty()) {
        state front = q.front();
        q.pop();
        
        for(auto child: child_m(front)) {
            dm[child.ff][child.ss] = dm[front.ff][front.ss] + 1;
            q.push(child);
        }
    }
}

void bfs_per() {
    queue<state> q;
    q.push(st);
    dp[st.ff][st.ss] = 0;

    while(!q.empty()) {
        state front = q.front();
        q.pop();

        for(auto child: child_p(front)) {
            q.push(child);
            dp[child.ff][child.ss] = dp[front.ff][front.ss] + 1;
        }
    }

}
void solve()
{
    cin>>n>>m;
    g.resize(n, vector<char>(m,'a'));
    dm.assign(n, vi(m,INF));
    dp.assign(n, vi(m,INF));

    rep(i,0,n) {
        rep(j,0,m) {
            char ch;
            cin>>ch;
            g[i][j] = ch;
            if(ch == 'M') monsters.eb(i,j);
            if((ch == '.' || ch == 'A') && (i == n-1 || i== 0 || j==0 || j==m-1)) {
                exits.eb(i,j);
            }
            if(ch == 'A') st = {i,j};
        }
    }

    bfs_mon();

    bfs_per();
    int minn = INT_MAX;
    // pr(dp);
    // pr(dm);
    for(auto exit : exits) {
        pr(exit);
        if(dp[exit.ff][exit.ss] < dm[exit.ff][exit.ss]) {
            minn = min(minn, dp[exit.ff][exit.ss]);
        }
    }

    if(minn!= INT_MAX) {
        pry;
        cout<<minn<<nline;
    }else prn;
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
