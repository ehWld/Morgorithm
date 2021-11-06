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
#include <stack>

using namespace std;
using pii = pair<int, int>;
using lint = long long;

/* [🦔] [💜] [✨] */

string S;

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> S;

    int N = int(S.length());
    stack<int> st;
    int len = 0;

    for(int i=0; i<N; i++) {
        switch(S[i]) {
            case '(':
                st.push(-1);
                break;
            case ')':
                len = 0;
                while(st.top() >= 0) {
                    len += st.top();
                    st.pop();
                }
                st.pop(); // ( 제거
                len *= st.top();
                st.pop(); // K 제거
                st.push(len);
                break;
            default:
                if(i < N-1 && S[i+1] == '(') st.push(S[i]-48);
                else st.push(1);
        }
    }

    int ans = 0;
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    cout << ans << '\n';

    return 0;
}
