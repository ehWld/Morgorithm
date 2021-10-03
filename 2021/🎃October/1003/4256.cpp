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
int T, n, top, preorder[1002], inorder[1002];

void divide(int left, int right) {
    if(left > right) return;

    if(left == right) {
        cout << inorder[left] << ' ';
        top++;
        return;
    }

    for(int i=left; i<=right; i++) {
        if(inorder[i] != preorder[top]) continue;

        top++;
        divide(left, i-1);
        divide(i+1, right);
        cout << inorder[i] << ' ';
        break;
    }
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i=0; i<n; i++) cin >> preorder[i];
        for(int i=0; i<n; i++) cin >> inorder[i];
        top = 0;
        divide(0, n-1);
        cout << '\n';
    }

    return 0;
}
