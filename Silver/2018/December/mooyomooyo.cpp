#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#define vec vector
#pragma warning(disable:6385)
using namespace std;
ifstream fin("mooyomooyo.in");
ofstream fout("mooyomooyo.out");

int N, K; 
vec<vec<int>> board; 
vec<vec<pair<int, int>>> regions; 
bool vis[10][100]; 
vector<pair<int, int>> cur_region; 

void dfs(int x, int y, int c) {
	if (!vis[x][y] && x >= 0 && y >= 0 && x < 10 && y < N && board[x][y] == c) {
		vis[x][y] = true;
		cur_region.push_back(make_pair(x, y));
		dfs(x + 1, y, c); 
		dfs(x - 1, y, c);
		dfs(x, y + 1, c); 
		dfs(x, y - 1, c);
	}
}

void clear() {
	for (int i = 0; i < regions.size(); i++) { for (int j = 0; j < regions[i].size(); j++) { board[regions[i][j].first][regions[i][j].second] = 0; } }
}

void gravity() {
	for (int i = 0; i < 10; i++) {
		vector<int> shift; 
		for (int j = N - 1; j >= 0; j--) { if (board[i][j] != 0) shift.insert(begin(shift), board[i][j]); }
		for (int j = 0; j < N; j++) {
			if (j < shift.size()) { board[i][N - 1 - j] = shift[shift.size() - 1 - j]; }
			else board[i][N - 1 - j] = 0; 
		}

	}
}

int main() {
	read >> N >> K; 
	board.resize(10); for (int i = 0; i < 10; i++) { board[i].resize(N); }
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			char a;
			read >> a;
			board[j][i] = a - '0';
		}
	}
	while (1) {
		gravity(); 
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] != 0 && !vis[i][j]) {
					cur_region.clear(); 
					dfs(i, j, board[i][j]);
					if ((int)cur_region.size() >= K) {
						regions.push_back(cur_region);
					}
				}
			}
		}
		clear();
		for (int m = 0; m < 10; m++) { for (int k = 0; k < N; k++) { vis[m][k] = false; } }
		if (regions.size() == 0) break;
		regions.clear();
		gravity();
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			write << board[j][i]; cout << board[j][i];
			if (j == 9) { write << endl; cout << endl; }
		}
	}

}
