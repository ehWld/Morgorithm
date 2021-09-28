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

int t, n;
vector<pii> arr;

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        arr.clear();

        cin >> n;
        int input;
        for(int i=0; i<n; i++) {
            cin >> input;
            arr.push_back({input, i+1});
        }

        sort(arr.begin(), arr.end());
        if(arr[n-1].first == 0) {
            cout << "0" << '\n';
            continue;
        }

        int l = 0;
        int r = n-1;
        while(arr[l].first == 0) l++;

        vector<pii> ans;
        while(l < r) {
            ans.push_back({arr[l].second, arr[r].second});
            arr[l].first--;
            arr[r].first--;
            if(l < n-1 && arr[l].first == 0) l++;
            if(arr[r].first < arr[r-1].first) {
                int tmp = r-1;
                while(tmp > 0 && arr[tmp-1].first > arr[r].first) tmp--;
                swap(arr[tmp], arr[r]);
            }
        }

        cout << ans.size() << '\n';
        for(auto &a: ans) {
            cout << a.first << ' ' << a.second << '\n';
        }
    }

    return 0;
}
