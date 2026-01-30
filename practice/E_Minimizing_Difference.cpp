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

#define int long long

//---- Debugger ---- //
#ifndef ONLINE_JUDGE
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
#endif
//----------------- //

const int MOD = 1000000007;

int n,k;
vi a;
vi pre;

bool valid(int l, int r) {
  int pos = upper_bound(all(a), r) - a.begin();
  int moves = 0;
  if(pos<n) {
    moves+= (pre[n-1] - (pos==0 ? 0 : pre[pos-1])) - (n-pos)*r;
  }
  pos = lower_bound(all(a),l) - a.begin();
  if(pos!=0) {
    moves+=pos*l - pre[pos-1];
  }
  return moves <= k;
}

bool check(int mid) {
  rep(i,0,n) {
    if(valid(a[i], a[i] + mid) || valid(a[i]-mid, a[i])) return true;
  }
  return false;
}

void solve()
{
  cin>>n>>k;
  a.resize(n);
  pre.resize(n);
  rep(i,0,n) cin>>a[i];
  sort(all(a));

  pre[0] = a[0];

  rep(i,1,n) {
    pre[i] = a[i] + pre[i-1];
  }

  int lo = 0, hi = *max_element(all(a)) - *min_element(all(a));
  int ans = -1;
  while(lo <= hi) {
    int mid = (lo + hi)/2;
    if(check(mid)) {
      hi=mid-1;
      ans = mid;
    } else lo = mid+1;
  }
  cout<<ans<<nline;
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
