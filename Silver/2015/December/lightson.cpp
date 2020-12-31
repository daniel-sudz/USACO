#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#define maxN 100
#pragma warning(disable:6385)
using namespace std;
using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using vii = vector<vi>; using vpii = vector<pii>; using vvpii = vector<vpii>; 
ifstream fin("lightson.in");
ofstream fout("lightson.out");

using vvvpii = vector<vvpii>; 
bool ok[maxN][maxN]{};
bool vis[maxN][maxN]{};
bool error = false; 
int N, M; 
vvvpii rooms;

void dfs(int x, int y) {
		if (!error && ok[x][y] && x >= 0 && y >= 0 && x < N && y < N && !vis[x][y]) {
			vis[x][y] = true;
			if (rooms[x][y].size() > 0) {
				for (int i = 0; i < rooms[x][y].size(); i++) { 
					ok[rooms[x][y][i].first][rooms[x][y][i].second] = true; 
				}
				rooms[x][y].clear();
				error = true;
			}
			else {
				dfs(x - 1, y); dfs(x + 1, y); dfs(x, y - 1); dfs(x, y + 1); 
			}
		}
}

void trycatch() {
	dfs(0, 0);
	if (error) {
		error = false; 
		for (int i = 0; i < N; i++) { for (int j = 0; j < N; j++) { vis[i][j] = false; } }
		trycatch();
	}
}

int main() {
	read >> N >> M; ok[0][0] = true; 
	rooms.resize(N); for (int i = 0; i < N; i++) { rooms[i].resize(N); }
	for (int i = 0; i < M; i++) {
		int x, y, a, b; read >> x >> y >> a >> b;
		x--; y--; a--; b--;
		rooms[x][y].pb(make_pair(a, b));
	}
	trycatch();
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) { if (ok[i][j]) ans++; }
	}; write << ans << endl; return ans;
}
