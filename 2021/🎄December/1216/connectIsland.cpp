#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int root[102];

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[2] < b[2];
}

void initRoot(int n) {
    for(int i=0; i<n; i++) {
        root[i] = i;
    }
}

int find(int n) {
    if(root[n] == n) return n;
    return root[n] = find(root[n]);
}

bool unionIsland(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    root[b] = a;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int count = 0;
    sort(costs.begin(), costs.end(), cmp);
    initRoot(n);

    for(auto &edge: costs) {
        if(!unionIsland(edge[0], edge[1])) continue;
        count++;
        answer += edge[2];
        if(count == n-1) break;
    }

    return answer;
}

int main() {
    vector<vector<int>> costs = {{0,1,5},{1,2,3},{2,3,3},{3,1,2},{3,0,4}, {2,4,6}, {4,0,7}};
    cout << solution(5, costs);
    return 0;
}
