#include <bits/stdc++.h>
using namespace std;
ifstream fin("pails.in");
ofstream fout("pails.out");

int X, Y, K, M; 
int vis[101][101];
int ans; 

void dfs(int x, int y, int k) {
	ans = min(ans, abs(M - x - y));
	if (k > 0 && k > vis[x][y]) {
		vis[x][y] = k; 
		dfs(X, y, k - 1); 
		dfs(x, Y, k - 1); 
		dfs(0, y, k - 1); 
		dfs(x, 0, k - 1); 
		dfs(min(X, x + y), y - min(X, x + y) + x, k - 1); 
		dfs(x - min(Y, y + x) + y, min(Y, y + x), k - 1);
	}
}

int main() {
	fin >> X >> Y >> K >> M;
	ans = M; 
	for (int i = 0; i < 101; i++) { for (int j = 0; j < 101; j++) vis[i][j] = -1;  }
	dfs(0, 0, K); 
	fout << ans << endl; return ans; 
}
