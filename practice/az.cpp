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
// vvi g;
vvi vis;
vvi dist;

int n, Sx, Sy, Fx, Fy;

using state = pii;

int dx[] = {2,2,1,-1,-2,-2,-1,1};
int dy[] = {1,-1,-2,-2,-1,1,2,2};

bool is_valid(int nx, int ny) {
    if(nx >=0 && nx < n && ny>=0 && ny<n) return 1;
    return 0;
}

vector<state> children(state node) {
    vector<state> childs;
    rep(i,0,8) {
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
    vis[st.ff][st.ss] = 1;
    q.push(st);
    dist[st.ff][st.ss] = 0;

    while(!q.empty()) {
        state front = q.front();
        q.pop();
        // pr(front);
        vis[front.ff][front.ss] = 1;
        for(auto v:children(front)) {
            if(!vis[v.ff][v.ss]) {
                // pr(v);
                q.push(v);
                vis[v.ff][v.ss] = 1;
                dist[v.ff][v.ss] = dist[front.ff][front.ss] + 1; 
            }
        }
    }
} 

int KnightWalk(int n, int Sx, int Sy, int Fx, int Fy)
{
    vis.assign(n,vi(n,0));
    dist.assign(n,vi(n,0));

    Sx--;
    Sy--;
    Fx--;
    Fy--;

    // pr(Sx, Sy);
    // pr(Fx, Fy);

	bfs({Sx, Sy});

    // pr(vis);

    if(vis[Fx][Fy]) {
        return dist[Fx][Fy];
    } else return -1;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{

		cin >> n >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(n, Sx, Sy, Fx, Fy) << "\n";
	}
}