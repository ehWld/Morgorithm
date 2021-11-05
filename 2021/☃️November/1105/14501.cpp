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
int day[20], pay[20], cache[20];

int dp(int n) {
    if(n > N) return 0;
    if(cache[n] != -1) return cache[n];
    if(n+day[n]-1 > N) return cache[n] = dp(n+1);

    int ret = max(pay[n] + dp(n+day[n]), dp(n+1));
    return cache[n] = ret;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> day[i] >> pay[i];
    }

    fill(cache, cache+20, -1);
    cout << dp(1) << '\n';

    return 0;
}
