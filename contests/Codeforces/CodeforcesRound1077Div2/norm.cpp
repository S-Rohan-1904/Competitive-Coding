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

void solve()
{
  int n;
  cin>>n;
  string str;
  cin>>str;
  string acc = "";
  int cnt = 0;
  rep(i,0,n) {
    if(str[i] == '1')cnt++;
  }
//   pr(str);
  rep(i,0,n) {
    acc+=str[i];
    if(str[i] == '1') acc = "1";

    if(acc == "0001") {
        cnt++;
        acc = "1";
        str[i-3]='1';
    } else if(acc == "1000") {
        cnt++;
        str[i]='1';
        acc = "1";
    } else if(acc == "001") {
        cnt++;
        acc= "1";
        str[i-2]='1';
    }

    // pr(cnt);
  }
  // pr(acc);
  
  if(n<4) {
    if(n==1) cout<<1<<nline;
    if(n==2) {
      if(str[0] == '1' && str[1] == '1') cout<<2<<nline;
      else cout<<1<<nline;
    }
    if(n==3) {
      if(str == "000" || str == "001") cout<<cnt+1<<nline;
      else cout<<cnt<<nline;
    }
    return;
  } else {
    if(acc == "100") {
        cnt++;
        str[n-1] = '1';
    }
    rrep(i,n,0) {
        acc+=str[i];
        if(str[i] == '1') acc = "1";
        if(acc == "0001") {
            cnt++;
            acc = "1";
            str[i+3]='1';
        } else if(acc == "1000") {
            cnt++;
            str[i]='1';
            acc = "1";
        } else if(acc == "001") {
            cnt++;
            acc= "1";
            str[i+2]='1';
        }

    // pr(cnt);
    }
  }

  bool temp = false;

  rep(i,0,n) {
    if(str[i] == '1') temp = true;
  }
  if(!temp) {
    // pr(str);
    int i =1;
    while(i<n) {
        cnt++;
        str[i] = '1';
        i = i+3;
    }

    string t ="";
    rep(i,n-3, n) t+=str[i];
    if(t == "100" || t== "1000") cnt++;
  }

  cout<<cnt<<nline;

}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
