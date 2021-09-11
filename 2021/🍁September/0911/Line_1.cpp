#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int cnt[30][35];

bool cmp(const pii &a, const pii &b) {
    if(a.second > b.second) return true;
    if(a.second == b.second && a.first < b.first) return true;
    return false;
}

string solution(vector<string> research, int n, int k) {
    string answer = "None";

    int len = int(research.size());
    for(int i=0; i<len; i++) {
        for(auto &c: research[i]) {
            cnt[c-97][i]++;
        }
    }

    vector<pii> issue;

    for(int c=0; c<26; c++) {
        int issueCnt = 0;
        for(int day=0; day<30-n; day++) {
            int sum = 0;
            bool flag = true;

            for(int i=day; i<day+n; i++) {
                if(cnt[c][i] < k) {
                    flag = false;
                    break;
                }
                sum += cnt[c][i];
            }
            if(flag && sum >= 2 * n * k) issueCnt++;
        }
        if(issueCnt > 0) issue.push_back({c, issueCnt});
    }

    sort(issue.begin(), issue.end(), cmp);
    if(!issue.empty()) answer = char(issue[0].first + 97);

    return answer;
}

int main() {

    vector<string> ans = {"yxxy", "xxyyy"};
    solution(ans, 2, 1);

    return 0;
}
