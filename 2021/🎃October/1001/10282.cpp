//  template.cpp
//  Copyright © 2021 도찡. All rights reserved.

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
using pii = pair<int, int>;
using lint = long long;
const int INF = 987654321;

/* [🦔] [💜] [✨] */

int t, n, d, c;
vector<pii> adj[100002];
vector<int> dist(100002, INF);

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pii> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        for(auto &a: adj[current]) {
            int next = a.first;
            int nextCost = a.second;

            if(dist[next] > cost + nextCost) {
                dist[next] = cost + nextCost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {

        cin >> n >> d >> c;

        fill(dist.begin(), dist.end(), INF);
        for(int i=0; i<=n; i++) adj[i].clear();

        int a, b, s;
        for(int i=0; i<d; i++) {
            cin >> a >> b >> s;
            adj[b].push_back({a, s});
        }

        dijkstra(c);

        int cnt = 0, ans = 0;
        for(int i=1; i<=n; i++) {
            if(dist[i] == INF) continue;
            cnt++;
            ans = max(ans, dist[i]);
        }
        cout << cnt << ' ' << ans << '\n';
    }

    return 0;
}
