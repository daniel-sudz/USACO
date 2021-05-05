#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
using namespace std;
ifstream fin("clocktree.in");
ofstream fout("clocktree.out");

int N;
int evenSum = 0;
int evenCount = 0;
int times[2500];
bool vis[2500];
vector<vector<int>> graph;

void dfs (int node, int distance) {
    if (!vis[node]) {
        vis[node] = true;
        evenSum += (distance % 2 ? times[node] * -1 : times[node]);
        evenCount += (distance % 2 == 0);
        for(int neighbors: graph[node]) {
            dfs(neighbors, distance + 1);
        }
    }
}

int main () {
    read >> N;
    graph.resize(N);
    for (int i = 0; i < N; i ++) {
        read >> times[i];
    }
    for (int i = 1; i < N; i ++) {
        int a, b; read >> a >> b; a --; b --;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(0, 0);
    evenSum = ((evenSum % 12) + 12) % 12; // normalize evenSum to be positive & mod 12
    if (evenSum == 1)
        write << evenCount << endl;
    else if (evenSum == 11)
        write << N - evenCount << endl;
    else if (evenSum == 0)
        write << N << endl;
    else
        write << 0 << endl;
}
