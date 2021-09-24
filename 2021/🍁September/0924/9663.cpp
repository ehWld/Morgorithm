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
int N, visit[15][15];

void check(int r, int c, int add) {
    for(int i=0; i<N; i++) {
        visit[r][i] += add;
        visit[i][c] += add;
    }
    visit[r][c] -= add;

    int dr[4] = {-1, -1, 1, 1};
    int dc[4] = {-1, 1, -1, 1};
    for(int i=0; i<4; i++) {
        int cr = r + dr[i], cc = c + dc[i];
        while(cr >= 0 && cr < N && cc >= 0 && cc < N) {
            visit[cr][cc] += add;
            cr += dr[i];
            cc += dc[i];
        }
    }
}

lint dfs(int r, int c) {
    if(r >= N-1) return 1;

    check(r, c, 1);
    lint ret = 0;

    for(int i=0; i<N; i++) {
        if(visit[r+1][i]) continue;
        ret += dfs(r+1, i);
    }

    check(r, c, -1);
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    lint ans = 0;
    for(int i=0; i<N; i++) ans += dfs(0, i);
    cout << ans;

    return 0;
}
