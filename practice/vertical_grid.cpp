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
using state = pii;
int n,k;
vvi g;
vector<vector<state>> comp_color;
vvi vis;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool ans = true;
void dfs(state st, int cc) {
    vis[st.ff][st.ss] = 1;
    comp_color[cc].eb(st);

    rep(i,0,4) {
        int nx = st.ff + dx[i];
        int ny = st.ss + dy[i];
        if(nx<n && nx>=0 && ny<10 && ny>=0 && g[nx][ny] == g[st.ff][st.ss] && !vis[nx][ny] && g[nx][ny] != 0) {
            // comp_color[cc].eb(nx,ny);
            // vis[nx][ny] = 1;
            dfs({nx,ny}, cc);
        }
    }    
}

void solve()
{
    cin>>n>>k;

    g.resize(n, vi(10));
    comp_color.resize(10*n);
    vis.assign(n, vi(10, 0));

    rep(i,0,n) {
        string str;
        cin>>str;

        rep(j,0,10) {
            g[i][j] = str[j] - '0';
        }
    }

    // pr(g);

    while(ans) {
        ans = false;
        // colouring
        int cc = 0;
        rep(i,0,n) {
            rep(j,0,10) {
                if(!vis[i][j] && g[i][j] != 0 && g[i][j] != -1) {
                    dfs({i,j}, cc);
                    if(comp_color[cc].size()>=k) {
                        ans = true;
                        for(state s : comp_color[cc]) {
                            g[s.ff][s.ss] = -1;
                        }
                    }
                    cc++;
                }
            }
        }

        //gravity
        rep(j,0,10) {
            queue<int> temp;
            rep(i,0,n) {
                if(g[i][j] != 0 && g[i][j] != -1) {
                    temp.push(g[i][j]);
                }
            }

            rep(i,0,n) {
                if(i <= n-temp.size()-1) g[i][j] = 0;
                else {
                    int front = 0;
                    if(!temp.empty()) {
                        front = temp.front();
                        temp.pop();
                    }
                    g[i][j] = front;
                }
            }
        }
        comp_color.clear();
        comp_color.resize(10*n);
        vis.assign(n, vi(10, 0));


    }

    rep(i,0,n) {
        rep(j,0,10) {
            cout<<g[i][j];
        }
        cout<<nline;
    }
    
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
