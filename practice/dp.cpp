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

int dp[1001][4][4];

int countNumberOfValidStrings(int idx, int prevChar, int firstChar, string s, int n) {
    // pruning
    // base case
    if(idx == n) {
        if(prevChar != firstChar) return 1;
        return 0;
    }
    // cache check
    if(firstChar != -1 && dp[idx][prevChar][firstChar] != -1) {
        return dp[idx][prevChar][firstChar];
    }
    // transition
    int ans = 0;
    int newFirstChar = firstChar;

    if(s[idx] == '?') {
        for(int ch = 0; ch < 4; ch++) {
            if(ch == prevChar) continue;
            if(idx == 0) newFirstChar = ch;
            ans += countNumberOfValidStrings(idx + 1, ch, newFirstChar, s, n);
        }
    } else if(s[idx] - 'A' != prevChar) {
        if(idx == 0) newFirstChar = s[idx] - 'A';
        ans = countNumberOfValidStrings(idx + 1, s[idx] - 'A', newFirstChar, s, n);
    }
    // save and return
    if(prevChar != -1) dp[idx][prevChar][firstChar] = ans;

    return ans;
}

string str;

void generateString(int idx, int prevChar, int firstChar, string s, int n) {
    if(idx == n) {
        return;
    }
    int newFirstChar = firstChar;

    if(s[idx] == '?') {
        for(int ch = 0; ch < 4; ch++) {
            if(ch == prevChar) continue;
            if(idx == 0) newFirstChar = ch;
            if(countNumberOfValidStrings(idx + 1, ch, newFirstChar, s, n) > 0) {
                str.push_back('A' + ch);
                generateString(idx + 1, ch, newFirstChar, s, n);
                return;
            }
        }
    } else if(s[idx] - 'A' != prevChar) {
        if(idx == 0) newFirstChar = s[idx] - 'A';
        if(countNumberOfValidStrings(idx + 1, s[idx] - 'A', newFirstChar, s, n) > 0) {
            str.push_back(s[idx]);
            generateString(idx + 1, s[idx] - 'A', newFirstChar, s, n);
            return;
        }
    }
}


void solve() {
    string s;
    cin>>s;

    memset(dp, -1, sizeof(dp));

    cout << countNumberOfValidStrings(0,-1,-1, s, s.size()) << nline;

    generateString(0,-1,-1,s,s.size());

    cout<<str<<nline;

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
