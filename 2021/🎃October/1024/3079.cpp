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
vector<lint> v;

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    lint a;
    lint maxWait = 0;
    for(int i=0; i<N; i++){
        cin >> a;
        maxWait = max(maxWait, a);
        v.push_back(a);
    }

    lint left = 0;
    lint right = maxWait * M;
    lint ans = 1e18;

    while(left<=right){
        lint mid = (left+right)/2;
        lint tmp = 0;
        for(int i=0; i<v.size(); i++){
            tmp += (mid/v[i]);
        }

        if(tmp>=M){
            ans = min(ans, mid);
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }

    cout<<ans<<"\n";

    return 0;
}
