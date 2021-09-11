#include <string>
#include <vector>

using namespace std;
using lint = long long;

pair<lint, vector<int>> priSum[103];

int find(int cur) {
    if(priSum[cur].first != 0) return cur;

    int ans = 0;
    lint value = 0;
    for(int i=1; i<=100; i++) {
        if(priSum[i].first > value) {
            value = priSum[i].first;
            ans = i;
        }
    }
    return ans;
}

vector<int> solution(vector<vector<int>> jobs) {
    vector<int> answer;

    int N = int(jobs.size());
    lint time = jobs[0][0];
    int idx = 0;
    int cur = 0;
    int complete = 0;

    while(complete < N) {
        while(idx < N && jobs[idx][0] <= time) {
            int num = jobs[idx][2];
            int pri = jobs[idx][3];
            priSum[num].first += pri;
            priSum[num].second.push_back(jobs[idx][1]);
            idx++;
        }

        int pre = cur;
        cur = find(cur);
        if(pre != cur) answer.push_back(cur);
        complete += priSum[cur].second.size();
        for(auto &t: priSum[cur].second) time += t;
        priSum[cur].first = 0;
        priSum[cur].second.clear();
    }

    return answer;
}

int main() {

    vector<vector<int>> jobs = {{0, 2, 3, 1}, {5, 3, 3, 1}, {10, 2, 4, 1}};


    solution(jobs);

    return 0;
}
