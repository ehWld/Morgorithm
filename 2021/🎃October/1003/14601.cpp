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

int K, x, y, arr[130][130];
int tile = 1;

struct point {
    int r;
    int c;

    point operator+ (point& p) {
        return {r+p.r, c+p.c};
    }
};

int direction(point start, int size, point filled) {
    if(filled.r < start.r + size) {
        if(filled.c < start.c + size) return 0;
        else return 1;
    }
    else {
        if(filled.c < start.c + size) return 2;
        else return 3;
    }
}

void divide(point start, int k, point filled) {
    if(k == 0) return;

    int size = pow(2, k-1);
    int dir = direction(start, size, filled);
    int curTile = tile;
    point nfill[4] = {{size-1, size-1}, {size-1, size}, {size, size-1}, {size, size}};
    point nstart[4] = {{0, 0}, {0, size}, {size, 0}, {size, size}};
    tile++;

    for(int i=0; i<4; i++) {
        if(i == dir) {
            divide(start+nstart[i], k-1, filled);
            continue;
        }
        arr[start.r + nfill[i].r][start.c + nfill[i].c] = curTile;
        divide(start+nstart[i], k-1, start+nfill[i]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> K >> x >> y;
    int size = pow(2, K);
    arr[size - y][x - 1] = -1;
    divide({0,0}, K, {size - y, x - 1});

    for(int r=0; r<size; r++) {
        for(int c=0; c<size; c++) {
            cout << arr[r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
