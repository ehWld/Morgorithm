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

long countMoves(vector<int> numbers) {
    int n = numbers.size();
    int maxNum = 0;
    lint sum = 0;
    for(int i=0; i<n; i++) {
        maxNum = max(maxNum, numbers[i]);
    }
    for(int i=0; i<n; i++) {
        sum += maxNum - numbers[i];
    }

    if(sum == 0) return 0;

    long x = n-1 - (sum % (n-1));
    long answer = (n * x + sum) / (n-1);

    return answer;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> numbers = {5, 5, 6, 8, 8, 5};
    countMoves(numbers);

    return 0;
}
