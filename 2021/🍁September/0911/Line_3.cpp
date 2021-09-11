#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

const int MAX = 1000000;

int minFactor[MAX];

void eratosthenes(void)
{
    minFactor[0] = minFactor[1] = -1;
    for (int i = 2; i <= MAX; i++)
        minFactor[i] = i;
        int sqrtN = int(sqrt(MAX));
        for (int i = 2; i <= sqrtN; i++)
            if (minFactor[i] == i)
            for (int j = i*i; j <= MAX; j += i)
                if (minFactor[j] == j)
            minFactor[j] = i;
}

queue<int> factor(int N)
{
    eratosthenes();
    queue<int> result;
    int copy = N;
    while (copy > 1)
    {
        result.push(minFactor[copy]);
        copy /= minFactor[copy];
    }
    return result;
}

vector<int> dc(vector<int> arr, queue<int> factor) {
    if(factor.empty()) return arr;

    int len = int(arr.size());
    int p = factor.front();
    factor.pop();
    vector<int> divide[p];
    vector<int> ret;

    for(int i=0; i<len; i++) {
        divide[i%p].push_back(arr[i]);
    }
    for(int i=0; i<p; i++) {
        vector<int> tmp = dc(divide[i], factor);
        ret.insert(ret.end(), tmp.begin(), tmp.end());
    }

    return ret;
}

vector<int> solution(int n) {
    vector<int> answer;
    vector<int> arr;
    for(int i=1; i<=n; i++) arr.push_back(i);

    return dc(arr, factor(n));
}

int main() {

    vector<int> ans = solution(12);

    return 0;
}
