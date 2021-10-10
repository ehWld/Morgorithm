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

int N;
bool arr[4000][7000];

void makeStart(int r, int c) {
    arr[r][c+2] = true;
    arr[r+1][c+1] = true;
    arr[r+1][c+3] = true;
    for(int i=0; i<5; i++) arr[r+2][c+i] = true;
}

void divide(int k, int r, int c) {
    if(k==0) {
        makeStart(r, c);
        return;
    }

    divide(k-1, r, c + 6*pow(2, k-2));
    divide(k-1, r + 3*pow(2, k-1), c);
    divide(k-1, r + 3*pow(2, k-1), c + 6*pow(2, k-1));
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    int k = log2(N/3);
    int R = N;
    int C = 6*pow(2, k) - 1;

    divide(k, 0, 0);

    for(int r=0; r<R; r++) {
        for(int c=0; c<C; c++) {
            if(arr[r][c]) cout << "*";
            else cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
