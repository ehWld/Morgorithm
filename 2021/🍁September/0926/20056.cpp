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

struct fire{
    int m, s, d;

    fire& operator +=(const fire& rhs) {
        m += rhs.m; s += rhs.s;
        if(d == -1) return *this;
        if(d == 0) d += rhs.d;
        else if((d%2) != (rhs.d%2)) d = -1;
        return *this;
    }
};

int N, M, K;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
pair<fire, int> arr[52][52], arr2[52][52];


void move(int r, int c) {
    if(arr[r][c].second == 0) return;
    if(arr[r][c].second == 1) {
        fire temp = arr[r][c].first;
        arr[r][c] = {fire{0, 0, 0}, 0};

        int nr = (r + temp.s * dr[temp.d]) % N;
        int nc = (c + temp.s * dc[temp.d]) % N;
        arr2[nr][nc].first += temp;
        arr2[nr][nc].second++;
        return;
    }

    int newM = arr[r][c].first.m / 5;
    int newS = arr[r][c].first.s / arr[r][c].second;
    int d = arr[r][c].first.d;
    arr[r][c] = {fire{0, 0, 0}, 0};

    if(newM == 0) return;

    for(int i=0; i<4; i++) {
        int newD;
        if(d == -1) newD = 2*i + 1;
        else newD = 2*i;
        int nr = (r + newS * dr[newD]) % N;
        int nc = (c + newS * dc[newD]) % N;

        arr2[nr][nc].first += fire{newM, newS, newD};
        arr2[nr][nc].second++;
    }
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    dr[0] += N; dr[1] += N; dr[7] += N;
    dc[5] += N; dc[6] += N; dc[7] += N;

    int r, c, m, s, d;
    for(int i=0; i<M; i++) {
        cin >> r >> c >> m >> s >> d;
        arr[r-1][c-1].first += fire{m, s, d};
        arr[r-1][c-1].second++;

    }

    for(int i=0; i<K; i++) {
        for(int r=0; r<N; r++) {
            for(int c=0; c<N; c++) {
                move(r, c);
            }
        }

        for(int r=0; r<N; r++) {
            for(int c=0; c<N; c++) {
                arr[r][c] = arr2[r][c];
                arr2[r][c] = {fire{0, 0, 0}, 0};
            }
        }
    }

    int ans = 0;
    for(int r=0; r<N; r++) {
        for(int c=0; c<N; c++) {
            if(arr[r][c].second == 1) ans += arr[r][c].first.m;
            else ans += (arr[r][c].first.m / 5) * 4;
        }
    }

    cout << ans << '\n';

    return 0;
}
