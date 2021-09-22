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
int L, C;
string arr[20];
bool isVow[20];

void dfs(int n, int vow, int con, string password) {
    password += arr[n];
    if(arr[n] == "a" || arr[n] == "e" || arr[n] == "i" || arr[n] == "o" || arr[n] == "u") vow++;
    else con++;

    if(password.length() == L) {
        if(vow >= 1 && con >= 2) cout << password << '\n';
        return;
    }

    for(int i=n+1; i<C; i++) {
        dfs(i, vow, con, password);
    }
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> L >> C;
    for(int i=0; i<C; i++) cin >> arr[i];
    sort(arr, arr+C);

    for(int i=0; i<C; i++) dfs(i, 0, 0, "");

    return 0;
}
