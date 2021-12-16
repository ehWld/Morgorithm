//
//  pathFindGame.cpp
//  2021
//
//  Created by Dozzing on 2021/12/17.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int right;
    int left;
};

node tree[10002];
int root;

bool cmp(const pair<int, vector<int>> &a, const pair<int, vector<int>> &b) {
    return a.second[1] > b.second[1];
}

void insert(int n, vector<vector<int>> nodeinfo) {
    if(n == root) return;
    int index = root;
    while(true) {
        if(nodeinfo[n-1][0] < nodeinfo[index-1][0]) {
            if(tree[index].left < 1) {
                tree[index].left = n;
                break;
            }
            else index = tree[index].left;
        }
        else {
            if(tree[index].right < 1) {
                tree[index].right = n;
                break;
            }
            else index = tree[index].right;
        }
    }
}

void preorder(int index, vector<int>* ret) {
    if(index < 1) return;

    ret->push_back(index);
    preorder(tree[index].left, ret);
    preorder(tree[index].right, ret);
}

void postorder(int index, vector<int>* ret) {
    if(index < 1) return;

    postorder(tree[index].left, ret);
    postorder(tree[index].right, ret);
    ret->push_back(index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<pair<int, vector<int>>> node;

    int len = int(nodeinfo.size());
    for(int i=0; i<len; i++) {
        node.push_back({i+1, nodeinfo[i]});
    }
    sort(node.begin(), node.end(), cmp);
    root = node[0].first;
    for(auto &n: node) insert(n.first, nodeinfo);

    vector<int>* pre = new vector<int>();
    vector<int>* post = new vector<int>();
    preorder(root, pre);
    postorder(root, post);
    answer.push_back(*pre);
    answer.push_back(*post);
    return answer;
}
