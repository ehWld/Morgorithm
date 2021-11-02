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
int root[202];

int find(int a) {
    if(root[a] == -1 || root[a] == a) return a;
    return root[a] = find(root[a]);
}

void merge(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    root[rootA] = rootB;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int input = 0;
    fill(root, root+202, -1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> input;
            if(input == 1) merge(i+1, j+1);
        }
    }

    vector<int> query;
    for(int i=0; i<M; i++) {
        cin >> input;
        query.push_back(input);
    }

    string ans = "YES";
    for(int i=0; i<M-1; i++) {
        int a = find(query[i]);
        int b = find(query[i+1]);
        if(a != b) {
            ans = "NO";
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}
