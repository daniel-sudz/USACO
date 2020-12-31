#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>; 
ifstream fin("mootube.in");
ofstream fout("mootube.out");

int N, Q; 
int sol = 0; 

class Node {
public: 
	int vid; 
	vector<pii> sibs; 
}; Node* G; 

void dfs(Node& n, int minrel, int rel, bool* vis) {
	if (!vis[n.vid] && (rel == -1 || rel >= minrel)) {
		vis[n.vid] = true; 
		sol++; 
		for (int i = 0; i < n.sibs.size(); i++) {
			if (rel == -1) {
				dfs(G[n.sibs[i].first], minrel, n.sibs[i].second, vis);
			}
			else dfs(G[n.sibs[i].first], minrel, min(rel, n.sibs[i].second), vis);
		}
	}
}

int main() {
	read >> N >> Q; 
	G = new Node[N]; 
	for (int i = 0; i < N; i++) { G[i].vid = i; }
	for (int i = 0; i < N - 1; i++) {
		int a, b, r;
		read >> a >> b >> r; 
		a--; b--; 
		pii p1 = make_pair(b, r); pii p2 = make_pair(a, r); 
		G[a].sibs.pb(p1); G[b].sibs.pb(p2);
	}
	for (int i = 0; i < Q; i++) {
		int minrel; read >> minrel; int a; read >> a; a--;
		sol = 0; bool* vis = new bool[N] {};
		dfs(G[a], minrel, -1, vis); 
		write << sol - 1 << endl; 
	}
}
