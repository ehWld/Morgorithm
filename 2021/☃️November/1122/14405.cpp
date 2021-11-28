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

string input;

/* [🦔] [💜] [✨] */

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> input;

    string output1 = regex_replace(input, regex("pi"), "_");
    string output2 = regex_replace(output1, regex("ka"), "_");
    string output3 = regex_replace(output2, regex("chu"), "_");
    string output = regex_replace(output3, regex("_"), "");

    if(output.length() == 0) cout << "YES" << '\n';
    else cout << "NO" << '\n';

    return 0;
}
