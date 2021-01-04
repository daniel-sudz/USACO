#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
//#pragma warning(disable:6385)
using namespace std;
using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using vii = vector<vi>; using vpii = vector<pii>; using vvpii = vector<vpii>;
ifstream fin("where.in");
ofstream fout("where.out");

struct PAIR { int x, y; PAIR(int intx, int inty) { x = intx; y = inty; } };
int N; 
int regions[26]; 
bool vis[20][20]; 
vector<vector<char>> pic; 
vector<vector<int>> ok; 

void dfs(PAIR low, PAIR high, int x, int y, char c) {
	if (!vis[x][y] && x >= low.x && x <= high.x && y >= low.y && y <= high.y && pic[x][y] == c) {
		vis[x][y] = true; 
		dfs(low, high, x - 1, y, c); 
		dfs(low, high, x + 1, y, c); 
		dfs(low, high, x, y - 1, c); 
		dfs(low, high, x, y + 1, c); 
	}
}

int main() {
	read >> N;
	pic.resize(N); for (int i = 0; i < N; i++) { pic[i].resize(N); }
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			read >> pic[j][i];
		}
	}
	for (int lowx = 0; lowx < N; lowx++) {
		for (int lowy = 0; lowy < N; lowy++) {
			for (int highx = lowx; highx < N; highx++) {
				for (int highy = lowy; highy < N; highy++) {
						PAIR low(lowx, lowy);
						PAIR high(highx, highy);
						for (int i = 0; i < 26; i++) { regions[i] = 0; }
						for (int i = 0; i < 20; i++) { for (int j = 0; j < 20; j++) vis[i][j] = 0; }
						for (int x = lowx; x <= highx; x++) {
							for (int y = lowy; y <= highy; y++) {
								if (!vis[x][y]) {
									char c = pic[x][y];
									regions[(int)c - 65] ++;
									dfs(low, high, x, y, c);
								}
							}

						}
						bool color1 = false; bool color2 = false; int amount = 0;
						for (int i = 0; i < 26; i++) {
							if (regions[i] == 1) {
								color1 = true; amount++;
							}
							if (regions[i] >= 2) {
								color2 = true; amount++;
							}
						}
						if (color1 && color2 && amount == 2) ok.push_back({ lowx, lowy, highx, highy });
				}
			}
		}
	}
	int ans = 0; 
	for (int i = 0; i < ok.size(); i++) {
		for (int j = 0; j < ok.size(); j++) {
			if (i != j || j == ok.size() - 1 ) {
				if (ok[i][2] <= ok[j][2] && ok[i][0] >= ok[j][0] && ok[i][3] <= ok[j][3] && ok[i][1] >= ok[j][1]) break;
				if (j == ok.size() - 1) ans++;
			}
		}
	}
	write << ans << endl; 
}
