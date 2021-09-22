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

int N, M;
bool visited[10];

void dfs(int n, vector<int> arr) {
    if(arr.size() >= M-1) {
        for(auto &a: arr) cout << a << ' ';
        cout << n << '\n';
        return;
    }

    visited[n] = true;
    arr.push_back(n);
    for(int i=n+1; i<=N; i++) {
        if(visited[i]) continue;
        dfs(i, arr);
    }

    visited[n] = false;
    arr.pop_back();
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    vector<int> arr;
    for(int i=1; i<=N; i++) dfs(i, arr);

    return 0;
}
