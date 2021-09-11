#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
using lint = long long;

const lint MAX =  1000000;
bool isPrime[MAX];

void eratos() {
    fill(isPrime, isPrime + MAX, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for(lint i=2; i<MAX; i++) {
        if(isPrime[i] == false) continue;
        for(lint j= 2*i; j>=0 && j<MAX; j+=i) {
            isPrime[j] = false;
        }
    }
}

bool prime(lint n) {
    lint tmp = sqrt(n);
    for(lint i=2; i<=tmp; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

vector<string> split(string s, string divid) {
    vector<string> v;
    char* c = strtok((char*)s.c_str(), divid.c_str());
    while (c) {
        v.push_back(c);
        c = strtok(NULL, divid.c_str());
    }
    return v;
}

int solution(int n, int k) {
    int answer = 0;
    string trans =  "";

    while(n) {
        trans += to_string(n % k);
        n /= k;
    }
    reverse(trans.begin(), trans.end());
    vector<string> ret = split(trans, "0");

    eratos();
    for(auto &num: ret) {
        lint lnum = stoll(num);

        if(lnum >= MAX && prime(lnum)) answer++;
        else if(lnum < MAX && isPrime[lnum]) answer++;
    }

    return answer;
}

int main() {
    eratos();
    for(int i=1; i<=1000000; i++){
        for(int k=3; k<=10; k++){
            solution(i, k);
        }
    }
    return 0;
}
