#include <bits/stdc++.h>
#define read fin
#define write fout
#define pb push_back
#pragma warning(disable:6385)
using namespace std;
using ll = long long;
using vi = vector<int>;

ifstream fin("closing.in");
ofstream fout("closing.out");

int N, M, del; 
int* bc; 

class Node {
public: 
    vi sibs; 
    int barn; 
};
Node* g; 

void dfs(int b1, bool* vis) {
    Node n1 = g[b1];
    if (!vis[n1.barn]) {
        vis[n1.barn] = true; 
        for (int i = 0; i < n1.sibs.size(); i++) {
            if (!vis[n1.sibs[i]]) {
                dfs(g[n1.sibs[i]].barn, vis);
            }
        }
    }
}

int main() {
    read >> N >> M; 
    g = new Node[N];
    bc = new int[N] {}; 
    for (int i = 0; i < N; i++) { g[i].barn = i; }
    for (int i = 0; i < M; i++) {
        int a, b; 
        read >> a >> b; 
        a--; b--; 
        g[a].sibs.pb(b);
        g[b].sibs.pb(a);
    }
    for (int i = 0; i < N; i++) {
        if (i != 0) {
            read >> del; del--;
            bc[del] = true; 
            for (int j = 0; j < g[del].sibs.size(); j++) {
                vi& sib = g[g[del].sibs[j]].sibs;
                for (int z = 0; z < sib.size(); z++) {
                    if (sib[z] == del) 
                        sib.erase(sib.begin() + z); 
                }
            }
            g[del].sibs.clear();
        }
        bool* vis = new bool[N] {}; 
        for (int f = 0; f < N; f++) {
            if (bc[f] == false) {
            dfs(f, vis);
                for (int k = 0; k < N; k++) {
                    if (vis[k] == false && bc[k] != true) {
                        write << "NO" << endl; break;
                    }
                    else if (k == N - 1) { write << "YES" << endl;}
                }
                break; 
            } 
        }

    }
}
