#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i < r; i++)
#define rrep(i, r, l) for (int i = r; i >=0; i--)
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
/*
we basically have to ensure either 1 is the majority in both or 0 is the majority in both

if ai = bi then we can delete it, but it can be used to delete a much larger 
let's say
000101 -> 101
000010 -> 010

cnt of 0 >= ceil(len/2)
ceil(len/2) = 3
000101 (cnt 0 = 4, cnt 1 = 2) -> 101 (cnt0 = 1, cnt1 = 2)
000010 (cnt 0 = 5, cnt 1 = 1) -> 010 (cnt0 = 2, cnt1 = 1)

when we delete all matching 0's or 1's
we can reduce cnt0 only if cnt1 >= ceil((len - matching 0's)/2) in both strings
we can reduce cnt1 only if cnt0 >= ceil((len - matching 1's)/2) in both strings

but we can pick indices


0000011 -> 0 is mode
0001111 -> 1 is mode

delete first index
0011
1111
delete entire string now since for both mode = 1

how do i prove that is it just seeing the above two conditions if not ans is no
if it already satisfy then ans is yes.

can't delete entire string
100111
011001
whatever indices i choose even if i delete them using my rules. Final string will nto satisfy if it doesn;t follow my rules
10101
01010
00000
11111

111000
111000

0101
1010

can never satify
00, 01, 10, 11

0000000011
1111100011


*/
void solve() {
    int n, q;
    cin>>n>>q;
    string s, t;
    cin>>s>>t;

    vi cnt0s(n, 0);
    vi cnt0t(n, 0);
    vi cnt1s(n, 0);
    vi cnt1t(n, 0);
    vi matching0(n, 0);
    vi matching1(n, 0);

    rep(i,0,n) {
        cnt1s[i] = (s[i] == '1' ? 1 : 0);
        cnt0s[i] = (s[i] == '0' ? 1 : 0);
        cnt1t[i] = (t[i] == '1' ? 1 : 0);
        cnt0t[i] = (t[i] == '0' ? 1 : 0);
        if(s[i] == t[i] && s[i] == '0') matching0[i] = 1;
        if(s[i] == t[i] && s[i] == '1') matching1[i] = 1;
    }

    rep(i,1,n) {
        cnt1s[i] += cnt1s[i-1];
        cnt0s[i] += cnt0s[i-1];
        cnt1t[i] += cnt1t[i-1];
        cnt0t[i] += cnt0t[i-1];
        matching0[i] += matching0[i-1];
        matching1[i] += matching1[i-1];
    }

    /*
    we can reduce cnt0 only if cnt1 >= ceil((len - matching 0's)/2) in both strings
we can reduce cnt1 only if cnt0 >= ceil((len - matching 1's)/2) in both strings
*/

    while(q--) {
        int l, r;
        cin>>l>>r;
        l--;
        r--;

        int curr0s = cnt0s[r] - (l ? cnt0s[l - 1] : 0);
        int curr0t = cnt0t[r] - (l ? cnt0t[l - 1] : 0);
        int curr1s = cnt1s[r] - (l ? cnt1s[l - 1] : 0);
        int curr1t = cnt1t[r] - (l ? cnt1t[l - 1] : 0);
        int currmatch0 = matching0[r] - (l ? matching0[l - 1] : 0);
        int currmatch1 = matching1[r] - (l ? matching1[l - 1] : 0);
        int len = r - l + 1;
        if(curr0s >= (len + 1)/2 && curr0t >= (len + 1)/2) pry;
        else if(curr1s >= (len + 1)/2 && curr1t >= (len + 1)/2) pry;
        else if(curr0s >= (len - currmatch1 + 1)/2 && curr0t >= (len - currmatch1 + 1)/2) pry;
        else if(curr1s >= (len - currmatch0 + 1)/2 && curr1t >= (len - currmatch0 + 1)/2) pry;
        else prn;
    }
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
