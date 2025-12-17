#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i < r; i++)
#define ll long long
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

int query(int start, const vi &nodes) {
  if (nodes.empty())
    return 0;

  printf("? %d %d", start, (int)nodes.size());
  for (auto x : nodes)
    printf(" %d", x);
  printf("\n");
  fflush(stdout);

  int res;
  scanf("%d", &res);
  return res;
}

void solve() {
  int n;
  scanf("%d", &n);

  vi len(n + 1);
  vi nodes(n);
  iota(all(nodes), 1);

  rep(i, 1, n + 1) { len[i] = query(i, nodes); }

  int max_len = 0, start = -1;
  rep(i, 1, n + 1) {
    if (len[i] > max_len) {
      max_len = len[i];
      start = i;
    }
  }

  vector<bool> ip(n + 1, true);
  vi testNodes = nodes;
  sort(all(testNodes), [&](int a, int b) { return len[a] < len[b]; });

  for (auto node : testNodes) {
    if (node == start)
      continue;

    if (ip[node]) {
      vi S;
      rep(j, 1, n + 1) {
        if (j != node && ip[j]) {
          S.eb(j);
        }
      }
      if (query(start, S) == max_len) {
        ip[node] = false;
      }
    }
  }

  vi ans;
  rep(i, 1, n + 1) {
    if (ip[i])
      ans.eb(i);
  }

  sort(all(ans), [&](int a, int b) { return len[a] > len[b]; });

  printf("! %d", (int)ans.size());
  for (auto x : ans)
    printf(" %d", x);
  printf("\n");
  fflush(stdout);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
