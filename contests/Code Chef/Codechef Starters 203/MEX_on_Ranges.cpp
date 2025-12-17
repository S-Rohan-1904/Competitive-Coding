#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i < r; i++)
#define ll long long
#define endl '\n'
#define prn cout << "NO" << endl
#define pry cout << "YES" << endl
#define vi vector<int>
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define inparr(v)                                                              \
  for (auto &x : v)                                                            \
    cin >> x;
#define prarr(v)                                                               \
  for (auto &x : v)                                                            \
    cout << x << " ";                                                          \
  cout << endl;
#define pii pair<int, int>

void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  vi nums;
  rep(i, 0, n + 1) {
    if (str[i] == '1')
      nums.eb(i);
  }
  vi a(n);
  int lo = 0, hi = n - 1;
  wile(lo <= hi) {}
  rep(i, 0, n) {
    a[i] = nums[i];
    a[n - i - 1] = nums[i + 1];
  }
  if (n % 2 != 0) {
    a[n / 2] = nums[n / 2];
  }
  prarr(nums);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}
