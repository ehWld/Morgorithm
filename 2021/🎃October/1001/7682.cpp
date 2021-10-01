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

bool check(string input, char turn) {
    bool flag = true;
    for(int r=0; r<3; r++) {
        flag = true;
        for(int c=0; c<3; c++) {
            if(input[3*r+c] != turn) flag = false;
        }
        if(flag) return true;
    }

    for(int c=0; c<3; c++) {
        flag = true;
        for(int r=0; r<3; r++) {
            if(input[3*r+c] != turn) flag = false;
        }
        if(flag) return true;
    }

    if(input[0] == input[4] && input[4] == input[8] && input[8] == turn) return true;
    if(input[2] == input[4] && input[4] == input[6] && input[6] == turn) return true;

    return false;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string input;
    while(true) {

        cin >> input;
        if(input == "end") break;

        int oCount = 0, xCount = 0, nCount = 0;
        char turn;
        for(int i=0; i<9; i++) {
            if(input[i] == 'O') oCount++;
            else if(input[i] == 'X') xCount++;
            else nCount++;
        }
        if(xCount - oCount == 1) turn = 'X';
        else if(xCount == oCount) turn = 'O';
        else { cout << "invalid\n"; continue; }

        if(!check(input, turn) && nCount != 0) { cout << "invalid\n"; continue; }

        bool flag = false;
        for(int i=0; i<9; i++) {
            if(input[i] == turn) {
                input[i] = '.';
                if(!check(input, 'X') && !check(input, 'O')) { flag = true; break; }
                input[i] = turn;
            }
        }
        if(flag) cout << "valid\n";
        else cout << "invalid\n";

    }

    return 0;
}
