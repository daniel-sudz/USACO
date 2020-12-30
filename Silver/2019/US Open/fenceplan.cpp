#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll = long long;
using vi = vector<int>;
ifstream fin("fenceplan.in");
ofstream fout("fenceplan.out");

int N, M; 
int minx = 0; int maxx = 0; int maxy = 0; int miny = 0; int ans = - 1; 
int* X; int* Y; 

class Node {
public: 
	int cow; 
	vi sibs; 
}; Node* G;

void dfs(Node n, bool* vis) {
	if (!vis[n.cow]) {
		vis[n.cow] = true;
		minx = min(minx, X[n.cow]); 
		maxx = max(maxx, X[n.cow]); 
		miny = min(miny, Y[n.cow]); 
		maxy = max(maxy, Y[n.cow]);
		for (int i = 0; i < n.sibs.size(); i++) {
			dfs(G[n.sibs[i]], vis); 
		}
	}
}

int main() {
	read >> N >> M; 
	X = new int[N]; Y = new int[N]; G = new Node[N]; 
	for (int i = 0; i < N; i++) { read >> X[i] >> Y[i]; G[i].cow = i;  }
	for (int i = 0; i < M; i++) {
		int a, b; 
		read >> a >> b; 
		a--; b--; 
		G[a].sibs.pb(b); G[b].sibs.pb(a); 
	}
	bool* vis = new bool[N] {}; 
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			miny = Y[i]; maxy = miny;
			minx = X[i]; maxx = minx; 
			dfs(G[i], vis);
			int sol = 2*(maxx - minx) + 2*(maxy - miny); 
			if (ans == -1 || sol < ans)
				ans = sol; 
		}
	}
	write << ans << endl; 
}
