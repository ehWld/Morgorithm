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

/* [🦔] [💜] [✨] */

int R, C, T, arr[102][102];
bool visited[102][102];

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> R >> C >> T;

    for(int r=0; r<R; r++) {
        for(int c=0; c<C; c++) {
            cin >> arr[r][c];
        }
    }

    int ans = 10001;
    queue<pair<pii, int>> qu;
    qu.push({{0,0}, 0});

    while(!qu.empty()) {
        int time = qu.front().second;
        pii current = qu.front().first;
        qu.pop();

        if(current.first==R-1 && current.second==C-1) {
            ans = min(ans, time);
            break;
        }

        if(arr[current.first][current.second] == 2) {
            ans = min(ans, time + R - current.first + C - current.second - 2);
        }

        for(int i=0; i<4; i++) {
            pii next = {current.first + dr[i], current.second + dc[i]};

            if(next.first<0 || next.first>=R || next.second<0 || next.second>=C) continue;
            if(visited[next.first][next.second] || arr[next.first][next.second] == 1) continue;

            visited[next.first][next.second] = true;
            qu.push({next, time+1});
        }
    }

    if(ans > T) cout << "Fail" << '\n';
    else cout << ans << '\n';

    return 0;
}
