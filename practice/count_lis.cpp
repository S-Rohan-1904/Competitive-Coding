#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n;
vector<int> arr;
pair<int,int> dp[1001];

pair<int,int> maxmerge(pair<int,int> a, pair<int,int> b) {
    if(a.first > b.first) return {a.first, a.second%MOD};
    else if(b.first > a. first) return {b.first, b.second%MOD};
    return {a.first, (a.second%MOD + b.second%MOD)%MOD};
}

pair<int,int> rec(int i) {
    if(dp[i].first != -1) return dp[i];
    pair<int,int> ans = {1,1};

    for(int j = 0; j < i; j++) {
        if(arr[i] > arr[j]) {
            pair<int,int> candidate = rec(j);
            candidate.first += 1;
            ans = maxmerge(ans, candidate);
        }
    }

    return dp[i] = ans;
}

void solve() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i] = {-1, -1};
    }

    pair<int, int> final_ans = {0, 0};

    for (int i = 0; i < n; i++) {
        final_ans = maxmerge(final_ans, rec(i));
    }

    cout << final_ans.second << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}