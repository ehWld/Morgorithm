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
int N;
int visited[1000002];

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;

    queue<int> qu;
    qu.push(N);
    visited[N] = N;

    while(!qu.empty()) {
        int current = qu.front();
        qu.pop();

        if(current == 1) break;

        if(current % 3 == 0 && !visited[current/3])  {
            qu.push(current/3);
            visited[current/3] = current;
        }
        if(current % 2 == 0 && !visited[current/2]) {
            qu.push(current/2);
            visited[current/2] = current;
        }
        if(!visited[current-1]) {
            qu.push(current - 1);
            visited[current - 1] = current;
        }
    }

    int current = 1;
    vector<int> ans;

    while(current != N) {
        ans.push_back(current);
        current = visited[current];
    }
    ans.push_back(N);

    int len = int(ans.size());
    cout << len-1 << '\n';

    for(int i=len-1; i>=0; i--) {
        cout << ans[i] << ' ';
    }

    return 0;
}
