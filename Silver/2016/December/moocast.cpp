#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll = long long;
using vi = vector<int>;
ifstream fin("moocast.in");
ofstream fout("moocast.out");

int N, ans; 
int* X; int* Y; int* P; 
class Node {
public: 
	int cow; 
	vi sibs; 
}; Node* G; 

bool reach(int x1, int x2, int y1, int y2, int p1) { // if cow1 can reach cow2
	int dis = abs(x1 - x2) * abs(x1 - x2);
	dis += abs(y1 - y2) * abs(y1 - y2);
	if (dis <= p1 * p1 ) return true; return false;
}

void dfs(Node n, bool* vis) {
	if (!vis[n.cow]) {
		vis[n.cow] = true; 
		for (int i = 0; i < n.sibs.size(); i++) {
			dfs(G[n.sibs[i]], vis); 
		}
	}
}

int main() {
	read >> N;
	X = new int[N]; Y = new int[N]; P = new int[N]; G = new Node[N]; 
	for (int i = 0; i < N; i++) {
		fin >> X[i] >> Y[i] >> P[i]; // read
		G[i].cow = i; // init graph 
	}
	for (int i = 0; i < N; i++) { // fill graph N^2
		for (int j = 0; j < N; j++) {
			if (j != i) {
				if (reach(X[i], X[j], Y[i], Y[j], P[i])) {
					G[i].sibs.pb(j); 
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		bool* vis = new bool[N] {}; int sol = 0; 
		dfs(G[i], vis); 
		for (int j = 0; j < N; j++) { if (vis[j]) sol++; }
		ans = max(ans, sol); 
	}
	write << ans << endl; 
}
