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
const int MAX = 200002;

vector<int> solve(int X, vector<int> arr, vector<int> query_values) {
    vector<int> answer;
    vector<int> index;

    int N = arr.size();
    for(int i=0; i<N; i++) {
        if(arr[i] == X) index.push_back(i+1);
    }

    int len = index.size();

    for(auto &q: query_values) {
        if(q > len) answer.push_back(-1);
        else answer.push_back(index[q-1]);
    }

    return answer;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> arr =  {1, 2, 20, 8, 8, 1, 2, 5, 8, 0};
    vector<int> query_values = {100, 2, 1, 3, 4 };
    solve(8, arr, query_values);

    return 0;
}
