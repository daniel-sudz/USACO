#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using vii = vector<vi>; using vpii = vector<pii>; using vvpii = vector<vpii>;
ifstream fin("countcross.in");
ofstream fout("countcross.out");

int N, K, R;
vector<vvpii> edges;
vector<vector<int>> distant; 
vpii cows;
int vis[100][100]{};

bool contains(int x1, int y1, int x2, int y2) {
	if (!(x1 >= 0 && x2 >= 0 && y1 >= 0 && y2 >= 0 && x1 < N && x2 < N && y1 < N && y2 < N)) return false; 
	for (int i = 0; i < edges[x1][y1].size(); i++) {
		pii edge = edges[x1][y1][i];
		if (edge.first == x2 && edge.second == y2) return true;
	} return false; 
}

// gate: 
// 0 -> not visited 
// 1 -> visited with gate
// 2 -> visited without gate
void dfs(int x, int y, bool gate) {
	if ((!vis[x][y] || (vis[x][y] == 1 && !gate) ) && x >= 0 && y >= 0 && x < N && y < N) {
		if (gate) vis[x][y] = 1;
		else vis[x][y] = 2; 
		if (contains(x, y, x + 1, y)) dfs(x + 1, y, true);
		else dfs(x + 1, y, gate || false); 
		if (contains(x, y, x - 1, y)) dfs(x - 1, y, true);
		else dfs(x - 1, y, gate || false);
		if (contains(x, y, x, y + 1)) dfs(x, y + 1, true);
		else dfs(x, y + 1, gate || false);
		if (contains(x, y, x, y - 1)) dfs(x, y - 1, true);
		else dfs(x, y - 1, gate || false);
	}
}

int main() {
	read >> N >> K >> R;
	edges.resize(N); distant.resize(N); for (int i = 0; i < N; i++) { edges[i].resize(N); distant[i].resize(N); }
	for (int i = 0; i < R; i++) {
		int a, b, c, d; read >> a >> b >> c >> d; a--; b--; c--; d--;
		edges[a][b].pb(make_pair(c, d));
		edges[c][d].pb(make_pair(a, b));
	}
	for (int i = 0; i < K; i++) {
		int a, b; read >> a >> b; a--; b--; 
		cows.pb(make_pair(a, b));
	}
	for (int i = 0; i < K; i++) {
		for (int m = 0; m < N; m++) { for (int j = 0; j < N; j++) vis[m][j] = 0; }
		dfs(cows[i].first, cows[i].second, false);
		for (int m = 0; m < K; m++) {
			pii cow = cows[m];
			if (vis[cow.first][cow.second] == 1) {
				distant[cows[i].first][cows[i].second] ++;
			}
		}
	}
	int ans = 0; 
	for (int i = 0; i < N; i++) { for (int j = 0; j < N; j++) ans += distant[i][j]; }
	write << ans / 2 << endl;  return ans / 2;
}
