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

using namespace std;
using pii = pair<int, int>;
using lint = long long;

/* [🦔] [💜] [✨] */
int V, ans;
vector<pii> adj[100002];
bool visited[100002];

int maxDistance(int node) {
    visited[node] = true;

    int answer = 0, first = 0, second = 0;
    for(auto &next: adj[node]) {
        if(visited[next.first]) continue;

        int dist = maxDistance(next.first)+ next.second;
        answer = max(answer, dist);

        if(dist > first) {
            second = first;
            first = dist;
        }
        else if(dist > second) second = dist;
    }
    ans = max(ans, second + first);
    return answer;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> V;
    int a, b, dist;
    for(int i=0; i<V; i++) {
        cin >> a;
        while(true) {
            cin >> b;
            if(b == -1) break;
            cin >> dist;
            adj[a].push_back({b, dist});
            adj[b].push_back({a, dist});
        }
    }

    maxDistance(1);
    cout << ans << '\n';

    return 0;
}
