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

/*
ans is max the number of columns(Any level is left with exactly 0 pieces (even if it is the topmost level))

for every level we need to find the sum of maximum elements in the same level and level above it

3 3
10 20 30
2 2 2 (10)
5 5 5 (20)
11 7 8 (30)

to make 10 as zero we need to take two 5's

we need to find the largest elements from row 1 to row i and find the number of elements such that sum >= instability index

how do i find just the right amount of elements but I have to iterate over multiset which will have O(N*M) elements
hence TLE. so think of some other way

probably some sorting based on instability
lower the instability score the better but higher the destabilization factor the better
i don't know if sorting can do that

sum of k greatest elements from row 1 to row i >= min(instability index from row 1 to row i)
The ans is k.
we can binary search on k
even if we binary search on k how can we get the greatest k element's sum quickly -> I know only O(K) method

there has to be something more simpler

I am thinking of bs on the answer
and then store only the k greater elements and keep checking
*/
int n, m;
vi v;
vvi arr;
bool check(int mid) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    int target = INT_MAX;
    rrep(i,n,0) {
        target = v[i];
        rep(j,0,m) {
            int x = arr[i][j];
            if (pq.size() < mid) {
                pq.push(x);
                sum += x;
            } 
            else if (x > pq.top()) {
                sum -= pq.top();
                pq.pop();
                
                pq.push(x);
                sum += x;
            }
            
        }
        if(sum >= target) return true;
    }
    return false;
}
void solve() {
    cin >> n >> m;
    pr(n, m);

    v.resize(n);
    inparr(v);

    arr.assign(n, vi(m));

    rep(i,0,n) {
        rep(j,0,m) {
            cin>>arr[i][j];
        }
    }

    int low = 1;
    int high = m;
    int ans = m;

    while(low <= high) {
        int mid = low + (high - low)/2;
        if(check(mid)) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }
    pr(2);
    cout << ans << nline;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
