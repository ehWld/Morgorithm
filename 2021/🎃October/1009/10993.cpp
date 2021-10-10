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

bool arr[2000][3000];

void divide(int n, int row, int col) {
    if(n == 1)  {
        arr[row][col] = true;
        return;
    }

    int R = pow(2, n) - 1;
    int C = pow(2, n+1) - 3;

    if(n%2 == 0) {
        for(int c=col; c<col+C; c++) arr[row][c] = true;
        for(int i=0; i<R; i++) {
            arr[row+i][col+i] = true;
            arr[row+i][col+C-1-i] = true;
        }
        divide(n-1, row+1, col+(R+1)/2);
    }
    else {
        for(int c=col; c<col+C; c++) arr[row+R-1][c] = true;
        for(int i=0; i<R; i++) {
            arr[row+R-1-i][col+i] = true;
            arr[row+R-1-i][col+C-1-i] = true;
        }
        divide(n-1, row+(R-1)/2, col+(R+1)/2);
    }
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    divide(N, 0, 0);

    int R = pow(2, N)-1;
    int C = pow(2, N+1)-3;

    if(N%2 == 0){
        for(int r=0; r<R; r++) {
            for(int c=0; c<C-r; c++) {
                if(arr[r][c]) cout << "*";
                else cout << ' ';
            }
            cout << '\n';
        }
    }
    else {
        for(int r=0; r<R; r++) {
            for(int c=0; c<(C+1)/2+r; c++) {
                if(arr[r][c]) cout << "*";
                else cout << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
