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

int t, R, C, k;
bool arr[12][20], visit[12][20];

bool boundaryCheck(pii p) {
    if(p.first < 0 || p.first >= R) return false;
    if(p.second < 0 || p.second >= C) return false;
    return true;
}

void check(int r, int c) {
    int d = 0;
    pii left = {r, c};
    pii right = {r, c};

    while(true) {
        pii nleft = {left.first-1, left.second-1};
        pii nright = {right.first-1, right.second+1};
        if(!boundaryCheck(nleft) || !boundaryCheck(nright)) break;
        if(!arr[nleft.first][nleft.second] || !arr[nright.first][nright.second]) break;
        left = nleft;
        right = nright;
        d++;
    }

    if(d < k) return;

    left = {r, c}; right = {r, c};
    visit[r][c] = true;
    while(d--) {
        pii nleft = {left.first-1, left.second-1};
        pii nright = {right.first-1, right.second+1};
        visit[nleft.first][nleft.second] = true;
        visit[nright.first][nright.second] = true;
        left = nleft;
        right = nright;
    }
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        fill(arr[0], arr[0]+12*20, false);
        fill(visit[0], visit[0]+12*20, true);

        cin >> R >> C >> k;
        char input;
        for(int r=0; r<R; r++) {
            for(int c=0; c<C; c++) {
                cin >> input;
                if(input == '*') {
                    arr[r][c] = true;
                    visit[r][c] = false;
                }
            }
        }

        for(int r=0; r<R; r++) {
            for(int c=0; c<C; c++) {
                if(arr[r][c]) check(r, c);
            }
        }

        bool ans = true;
        for(int r=0; r<R; r++) {
            for(int c=0; c<C; c++) {
                if(!visit[r][c]) ans = false;
            }
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
