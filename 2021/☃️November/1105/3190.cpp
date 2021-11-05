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

int N, K, L;
int board[102][102];
queue<pii> change;

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    fill(board[0], board[0]+102*102, -1);
    int r, c;
    for(int i=0; i<K; i++) {
        cin >> r >> c;
        board[r][c] = -2; // apple
    }
    cin >> L;
    int t; char dir;
    for(int i=0; i<L; i++) {
        cin >> t >> dir;
        if(dir == 'D') change.push({t, 0});
        else change.push({t, 1});
    }

    t = 1;
    pii head = {1, 1}, tail = {1, 1};
    board[1][1] = 0;
    while(true) {
        int dir = board[head.first][head.second];
        int nr = head.first + dr[dir];
        int nc = head.second + dc[dir];

        if(nr<=0 || nr>N || nc<=0 || nc>N) break;
        if(board[nr][nc] >= 0) break;

        if(board[nr][nc] == -1) { // no apple
            pii pre = tail;
            int dir = board[tail.first][tail.second];
            tail = { tail.first + dr[dir], tail.second + dc[dir] };
            board[pre.first][pre.second] = -1;
        }

        if(!change.empty() && change.front().first == t) {
            if(change.front().second == 0) dir = (dir + 1) % 4;
            else dir = (dir + 3) % 4;
            change.pop();
        }
        board[nr][nc] = dir;
        head = {nr, nc};

        t++;
    }

    cout << t << '\n';

    return 0;
}
