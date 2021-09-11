#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int INF = 60;
int dp[12][12];
int postSum[12];
int ryan[12];

int func(int n, int arrow) {
    if(n == 0) return 0;
    if(arrow <= 0) return -postSum[n];
    if(dp[n][arrow] != INF) return dp[n][arrow];

    if(arrow <= ryan[n]) return dp[n][arrow] = -n + func(n-1, arrow);
    if(ryan[n] == 0) return dp[n][arrow] = max(n + func(n-1, arrow-(ryan[n]+1)), func(n-1, arrow));
    return dp[n][arrow] = max(n + func(n-1, arrow-(ryan[n]+1)), -n + func(n-1, arrow));
}

vector<int> back(int n, int arrow) {
    int score = func(n, arrow);
    vector<int> ret;
    if(arrow <= 0) {
        for(int i=0; i<=n; i++) ret.push_back(0);
        return ret;
    }
    if(n == 0) {
        ret.push_back(arrow);
        return ret;
    }

    if(arrow <= ryan[n]) {
        ret = back(n-1, arrow);
        ret.insert(ret.begin(), 0);
    }
    else if(ryan[n] == 0) {
        if(score == func(n-1, arrow)) {
            ret = back(n-1, arrow);
            ret.insert(ret.begin(), 0);
        }
        else {
            ret = back(n-1, arrow-(ryan[n]+1));
            ret.insert(ret.begin(), ryan[n]+1);
        }
    }
    else {
        if(score == -n + func(n-1, arrow)) {
            ret = back(n-1, arrow);
            ret.insert(ret.begin(), 0);
        }
        else {
            ret = back(n-1, arrow-(ryan[n]+1));
            ret.insert(ret.begin(), ryan[n]+1);
        }
    }

    return ret;
}

vector<int> solution(int n, vector<int> info) {

    vector<int> answer;

    fill(dp[0], dp[0] + 12*12, INF);
    for(int i=10; i>=0; i--) {
        ryan[10-i] = info[i];
        if(9-i>=0) {
            if(info[i] == 0) postSum[10-i] = postSum[9-i];
            else postSum[10-i] = postSum[9-i] + 10-i;
        }
    }
    func(10,n);
    if(dp[10][n] <= 0) answer.push_back(-1);
    else answer = back(10, n);
    return answer;
}

int main() {
    vector<int> info = {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1};
    solution(9, info);
}
