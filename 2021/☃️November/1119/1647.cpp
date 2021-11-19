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

int N, M;
vector<pair<int, pii>> road;

int root[100002];

void initRoot() {
    for(int i=1; i<=N; i++) root[i] = i;
}

int find(int n) {
    if(root[n] == n) return n;
    return root[n] = find(root[n]);
}

bool unionCity(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;

    root[b] = a;
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int a, b, c;
    for(int i=0; i<M; i++) {
        cin >> a >> b >> c;
        road.push_back({c, {a, b}});
    }

    initRoot();
    sort(road.begin(), road.end());
    int selectCount = 0;
    int ans = 0;

    for(auto &current: road) {
        int cost = current.first;
        pii cities = current.second;

        if(!unionCity(cities.first, cities.second)) continue;
        ans += cost;
        selectCount++;

        if(selectCount >= N-2) break;
    }

    cout << ans << '\n';

    return 0;
}
