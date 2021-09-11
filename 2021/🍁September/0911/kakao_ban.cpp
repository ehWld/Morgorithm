#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

map<string, int> id_map;
int ban_cnt[1002];
bool report_list[1002][1002];

vector<string> split(string s, string divid) {
    vector<string> v;
    char* c = strtok((char*)s.c_str(), divid.c_str());
    while (c) {
        v.push_back(c);
        c = strtok(NULL, divid.c_str());
    }
    return v;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    int N = int(id_list.size());
    for(int i=0; i<N; i++) {
        id_map[id_list[i]] = i;
    }

    int rN = int(report.size());
    for(int i=0; i<rN; i++) {
        vector<string> parsed = split(report[i], " ");
        int a = id_map[parsed[0]];
        int b = id_map[parsed[1]];

        if(report_list[a][b] == false) ban_cnt[b]++;
        report_list[a][b] = true;
    }

    for(int a=0; a<N; a++) {
        int cnt = 0;
        for(int b=0; b<N; b++) {
            if(report_list[a][b] && ban_cnt[b] >= k) cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}
