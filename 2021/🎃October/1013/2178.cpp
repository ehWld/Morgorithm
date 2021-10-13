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

struct pos {
    int r, c, level;
};

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

int R, C;
bool maze[102][102];
bool visit[102][102];

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> R >> C;
    string input;
    for(int r=0; r<R; r++) {
        cin >> input;
        for(int c=0; c<C; c++) {
            if(input[c] == '1') maze[r][c] = true;
        }
    }

    queue<pos> qu;
    qu.push({0,0,1});
    visit[0][0] = true;
    int ans = 0;

    while(!qu.empty()) {
        pos current = qu.front();
        qu.pop();

        if(current.r == R-1 && current.c == C-1) {
            ans = current.level;
            break;
        }

        for(int i=0; i<4; i++) {
            int nr = current.r + dr[i];
            int nc = current.c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(visit[nr][nc] || !maze[nr][nc]) continue;
            visit[nr][nc] = true;
            qu.push({nr, nc, current.level + 1});
        }
    }

    cout << ans << '\n';

    return 0;
}
