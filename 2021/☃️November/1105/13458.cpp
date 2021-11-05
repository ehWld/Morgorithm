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

int N, B, C;
int arr[1000002];

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    cin >> B >> C;

    lint ans = N;

    for(int i=0; i<N; i++) {
        if(arr[i]-B <= 0) continue;
        ans += ceil(double(arr[i]-B) / C);
    }

    cout << ans << '\n';

    return 0;
}
