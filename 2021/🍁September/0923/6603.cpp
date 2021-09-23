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

int k, arr[15];
bool visited[15];

void dfs(int n, int cnt) {
    if(cnt == 6) {
        for(int i=0; i<k; i++)
            if(visited[i]) cout << arr[i] << ' ';
        cout << arr[n] << '\n';
    }

    visited[n] = true;
    for(int i=n+1; i<k; i++) {
        dfs(i, cnt+1);
    }
    visited[n] = false;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while(true) {
        cin >> k;
        if(k == 0) break;

        for(int i=0; i<k; i++) cin >> arr[i];

        for(int i=0; i<k; i++) dfs(i, 1);
        cout << '\n';
    }

    return 0;
}
