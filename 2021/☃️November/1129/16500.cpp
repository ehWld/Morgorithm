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
#include <regex>

using namespace std;
using pii = pair<int, int>;
using lint = long long;

/* [🦔] [💜] [✨] */

string S;
int N;

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> S >> N;
    string A;
    for(int i=0; i<N; i++) {
        cin >> A;
        S = regex_replace(S, regex(A), "_");
    }

    S = regex_replace(S, regex("_"), "");

    if(S.length() == 0) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}
