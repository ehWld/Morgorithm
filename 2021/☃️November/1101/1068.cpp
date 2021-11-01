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
int N, target, root;
vector<int> adj[52];

int leafCount(int node) {
    if(target == node) return 0;
    if(adj[node].empty()) return 1;

    int ans = 0;
    for(auto &child: adj[node]) {
        ans += leafCount(child);
    }
    if(ans == 0) return 1;
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    int input;
    for(int i=0; i<N; i++) {
        cin >> input;

        if(input < 0) root = i;
        else adj[input].push_back(i);
    }
    cin >> target;

    if(target == root) cout << 0;
    else cout << leafCount(root) << '\n';

    return 0;
}
