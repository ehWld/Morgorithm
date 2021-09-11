#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int cost[100000];
int intime[100000];
vector<int> carList;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    fill(intime, intime+100000, -1);
    int ntime = fees[0];
    int ncost = fees[1];
    int utime = fees[2];
    int ucost = fees[3];

    for(auto &r: records) {

        int time = stoi(r.substr(0,2)) * 60 + stoi(r.substr(3,2));
        int car = stoi(r.substr(6,4));
        if(cost[car] == 0 && intime[car] == -1) carList.push_back(car);

        if(intime[car] == -1) intime[car] = time;
        else {
            cost[car] += time - intime[car];
            intime[car] = -1;
        }
    }

    sort(carList.begin(), carList.end());

    for(auto &car: carList) {
        if(cost[car] < 0) continue;
        if(intime[car] >= 0) cost[car] += 1439 - intime[car];

        double exceed = max(0, cost[car] - ntime);
        int total = ncost + ceil(exceed / utime) * ucost;
        answer.push_back(total);
    }


    return answer;
}

int main() {
    vector<int> fees = {1, 461, 1, 10};
    vector<string> records = {"00:00 1234 IN"};

    solution(fees, records);

    return 0;
}
