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
#include <queue>

using namespace std;
using pii = pair<int, int>;
using lint = long long;

/* [🦔] [💜] [✨] */
int t, n, arr[200002];
deque<int> qu;

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];

        qu.push_back(arr[0]);
        for(int i=1; i<n; i++) {
            if(qu.front() > arr[i]) qu.push_front(arr[i]);
            else qu.push_back(arr[i]);
        }

        while(!qu.empty()) {
            cout << qu.front() << ' ';
            qu.pop_front();
        }
        cout << '\n';
    }

    return 0;
}
