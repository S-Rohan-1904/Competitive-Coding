#include <bits/stdc++.h>
using namespace std;
vi dist;
using pii = pair<int,int>;
void bfs01(int start) {
    deque<pii> dq;
    dq.push_back({0, start});
    dist[start] = 0;

    while(!dq.empty()) {
        pii front = dq.front();
        dq.pop_front();


    }
}