#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
int cache[3002];

int dp(int n) {
    if(cache[n] > 0) return cache[n];

    long long ret = 0;
    ret = cache[n-1];
    if(n >= 2) ret = (ret + cache[n-2]) % MOD;
    if(n >= 4) ret = (ret + cache[n-4]) % MOD;
    if(n >= 6) ret = (ret + cache[n-6]) % MOD;
    return cache[n] = ret;
}

int main() {
    int n;
    cin >> n;

    cache[0] = 1;
    cache[1] = 1;
    cout << dp(n);
    return 0;
}
