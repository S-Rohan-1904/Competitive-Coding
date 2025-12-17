#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i < r; i++)
#define ll long long
#define endl '\n'
#define prn cout << "NO" << endl
#define pry cout << "YES" << endl
#define vi vector<int>
#define pb push_back
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

bool distinct(int y, vi digits) {
  rep(i, 0, 4) {
    if (digits[y % 10] != 0) {
      return false;
    } else
      digits[y % 10] = 1;
    y /= 10;
  }
  return true;
}

void solve() {
  int y;
  cin >> y;
  vi digits(10);
  y += 1;
  while (!distinct(y, digits)) {
    y++;
  }
  cout << y << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // int t;
  // cin >> t;
  // while (t--)
  solve();
  return 0;
}
