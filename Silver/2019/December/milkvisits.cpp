#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
using namespace std;
ifstream fin("milkvisits.in");
ofstream fout("milkvisits.out");

int N, M;
vector<vector<int>> graph;
bool color[100001] = {};
int group[100001] = {};
int vis[100001] = {};
int maxgroup = 0;

void dfs(int curnode, int lastnode) {
    if (!vis[curnode]) {
        vis[curnode] = true;
        if (color[lastnode] != color[curnode]) {
            group[curnode] = ++maxgroup;
        }
        else {
            group[curnode] = group[lastnode];
        }
        for (int i: graph[curnode]) {
            dfs(i, curnode);
        }
    }
}


int main() {
    read >> N >> M;
    graph.resize(N + 1);
    // process colorings in second line
    for (int i = 1; i < N + 1; i ++) {
        char charcolor; read >> charcolor;
        if (charcolor == 'H' ) {
            color[i] = true;
        }
    }
    // build graph
    for (int i = 0; i < N - 1; i ++) {
        int from, to; read >> from >> to;
        graph[from].pb(to); graph[to].pb(from);
    }
    // build sets
    dfs(1, 1);
    // process questions
    for (int i = 0; i < M; i ++) {
        int from, to; read >> from >> to;
        char prefferedchar; read >> prefferedchar;
        bool preffered = prefferedchar == 'H';
        if (group[from] != group[to]) {
            write << '1';
        }
        else if (color[from] == preffered) {
            write << '1';
        }
        else {
            write << '0';
        }
    }
    write << endl;
}
