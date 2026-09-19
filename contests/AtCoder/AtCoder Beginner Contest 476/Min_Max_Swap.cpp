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

#define int long long

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

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

struct Node {
    int min_val, min_idx;
    int max_val, max_idx;
};

template <typename T>
class SegmentTree {
private:
    int n;
    vector<T> tree;
    T identity;
    function<T(T, T)> merge;

    void build(const vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, T val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    T query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return identity;
        if (l <= start && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        return merge(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
    }

    void get_final_array(int node, int start, int end, vector<T>& result) {
        if (start == end) {
            result[start] = tree[node];
            return;
        }
        int mid = start + (end - start) / 2;
        get_final_array(2 * node, start, mid, result);
        get_final_array(2 * node + 1, mid + 1, end, result);
    }

public:
    SegmentTree(const vector<T>& arr, T identity_val, function<T(T, T)> merge_func) {
        n = arr.size();
        identity = identity_val;
        merge = merge_func;
        tree.assign(4 * n, identity);
        if (n > 0) build(arr, 1, 0, n - 1);
    }

    void update(int idx, T val) {
        if (idx < 0 || idx >= n) return;
        update(1, 0, n - 1, idx, val);
    }

    T query(int l, int r) {
        if (l > r || l < 0 || r >= n) return identity;
        return query(1, 0, n - 1, l, r);
    }

    vector<T> extract() {
        vector<T> result(n);
        if (n > 0) get_final_array(1, 0, n - 1, result);
        return result;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Node> init_nodes(n);
    rep(i, 0, n) {
        int val;
        cin >> val;
        init_nodes[i] = {val, i, val, i};
    }

    Node identity = {2000000000, -1, -2000000000, -1};

    auto merge_min_max = [](Node L, Node R) {
        Node res;
        if (L.min_val < R.min_val) { 
            res.min_val = L.min_val;
            res.min_idx = L.min_idx;
        } else { 
            res.min_val = R.min_val;
            res.min_idx = R.min_idx; 
        }

        if (L.max_val > R.max_val) { 
            res.max_val = L.max_val;
            res.max_idx = L.max_idx;
        } else {
            res.max_val = R.max_val;
            res.max_idx = R.max_idx;
        }
        return res;
    };

    SegmentTree<Node> st(init_nodes, identity, merge_min_max);

    rep(q, 0, m) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        Node target = st.query(l, r);

        if (target.min_idx != target.max_idx) {
            st.update(target.min_idx, {target.max_val, target.min_idx, target.max_val, target.min_idx});
            st.update(target.max_idx, {target.min_val, target.max_idx, target.min_val, target.max_idx});
        }
    }

    vector<Node> ans = st.extract();

    rep(i, 0, n) {
        cout << ans[i].min_val << " ";
    }
    cout << nline;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
        solve();
}