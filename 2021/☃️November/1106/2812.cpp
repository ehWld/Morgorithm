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

int N, K;
string input;

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> K >> input;

    int len = 0;
    vector<int> st;

    for(int i=0; i<N; i++) {
        int current = input[i] - 48;

        while(!st.empty() && st.back() < current && len+(N-1-i) >= N-K) {
            st.pop_back();
            len--;
        }

        if(len < N-K) {
            st.push_back(current);
            len++;
        }
    }

    for(auto &n: st) cout << n;

    return 0;
}
