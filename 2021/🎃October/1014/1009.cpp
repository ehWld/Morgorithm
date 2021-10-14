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

int T;
lint a, b;

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> a >> b;
        lint ans = 1;

        for(int i=0; i<b; i++) {
            ans =  ( ans * (a % 10) )% 10;
        }

        cout << ans << '\n';
    }

    return 0;
}
