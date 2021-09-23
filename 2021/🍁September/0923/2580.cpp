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
int arr[10][10], N;
vector<pii> zero;

vector<int> check(int n) {
    bool visit[10] = {false, };
    vector<int> nums;
    int row = zero[n].first;
    int col = zero[n].second;
    int R = row/3 * 3;
    int C = col/3 * 3;

    for(int r=R; r<R+3; r++) {
        for(int c=C; c<C+3; c++) {
            visit[arr[r][c]] = true;
        }
    }

    for(int r=0; r<9; r++) {
        visit[arr[r][col]] = true;
    }

    for(int c=0; c<9; c++) {
        visit[arr[row][c]] = true;
    }

    for(int i=1; i<=9; i++) {
        if(!visit[i]) nums.push_back(i);
    }

    return nums;
}

bool dfs(int n) {
    if(n == N) return true;

    vector<int> nums = check(n);
    int row = zero[n].first;
    int col = zero[n].second;

    for(auto &num: nums) {
        arr[row][col] = num;
        if(dfs(n+1)) return true;
    }

    arr[row][col] = 0;
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for(int r=0; r<9; r++) {
        for(int c=0; c<9; c++) {
            cin >> arr[r][c];
            if(arr[r][c] == 0) zero.push_back({r, c});
        }
    }

    N = int(zero.size());
    dfs(0);

    for(int r=0; r<9; r++) {
        for(int c=0; c<9; c++) {
            cout << arr[r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
