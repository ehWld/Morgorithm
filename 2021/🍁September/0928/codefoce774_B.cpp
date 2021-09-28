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
vector<int> arr, arr2;

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> t;
    arr.resize(52);
    arr2.resize(52);

    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            arr2[i] = arr[i];
        }

        sort(arr2.begin(), arr2.begin() + n);
        int k = 0;
        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            int offset = i;
            while(offset < n) {
                if(arr2[i] == arr[offset]) break;
                offset++;
            }

            if(offset == i) continue;

            arr.erase(arr.begin() + offset);
            arr.insert(arr.begin(), arr2[i]);
            k++;
            vector<int> tmp;
            tmp.push_back(i+1);
            tmp.push_back(offset+1);
            tmp.push_back(offset-i);
            ans.push_back(tmp);
        }

        cout << k << '\n';
        for(auto &a: ans) {
            cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
        }
    }

    return 0;
}
