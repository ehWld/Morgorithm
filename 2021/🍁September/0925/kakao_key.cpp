#include <string>
#include <vector>
#include <iostream>

using namespace std;
using pii = pair<int, int>;

bool check(pii start, int N, vector<vector<int>> &key, vector<vector<int>> &lock) {
    for(int r=0; r<N; r++) {
        for(int c=0; c<N; c++) {
            if(lock[r][c] == key[start.first + r][start.second + c]) return false;
        }
    }
    return true;
}

vector<vector<int>> rotate(vector<vector<int>> key) {
    vector<vector<int>> ret;

    int N = int(key.size());
    ret.resize(N, vector<int>(N, 0));

    for(int r=0; r<N; r++) {
        for(int c=0; c<N; c++) {
            ret[N-c-1][r] = key[r][c];
        }
    }
    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = int(lock.size());
    int M = int(key.size());

    vector<vector<int>> newKey;
    newKey.resize(M+2*(N-1), vector<int>(M+2*(N-1), 0));
    for(int r=0; r<M; r++) {
        for(int c=0; c<M; c++) {
            newKey[r+N-1][c+N-1] = key[r][c];
        }
    }

    for(int i=0; i<4; i++) {
        newKey = rotate(newKey);

        for(int r=0; r<N+M-1; r++) {
            for(int c=0; c<N+M-1; c++) {
                if(check({r,c}, N, newKey, lock)) return true;
            }
        }
    }
    return false;
}
