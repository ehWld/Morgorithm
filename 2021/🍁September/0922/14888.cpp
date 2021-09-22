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
int N, arr[13];
int cnt[4];
lint max_ans = -1e10, min_ans = 1e10;

void dfs(int n, lint ret) {
    if(n >= N-1) {
        max_ans = max(max_ans, ret);
        min_ans = min(min_ans, ret);
        return;
    }

    for(int i=0; i<4; i++) {
        if(!cnt[i]) continue;

        cnt[i]--;
        if(i == 0) dfs(n+1, ret + arr[n+1]);
        else if(i == 1) dfs(n+1, ret - arr[n+1]);
        else if(i == 2) dfs(n+1, ret * arr[n+1]);
        else dfs(n+1, ret / arr[n+1]);
        cnt[i]++;
    }
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=0; i<4; i++) cin >> cnt[i];

    dfs(0, arr[0]);

    cout << max_ans << '\n' << min_ans;

    return 0;
}
