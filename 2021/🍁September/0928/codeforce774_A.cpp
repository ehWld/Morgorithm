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

int t;
string input;

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> input;
        int len = input.length();
        int a = 0, b = 0, c = 0;
        for(int i=0; i<len; i++) {
            if(input[i] == 'A') a++;
            if(input[i] == 'B') b++;
            if(input[i] == 'C') c++;
        }
        if(b == a + c) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
