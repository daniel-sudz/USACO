#include <bits/stdc++.h>
#include <unordered_set>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using vii = vector<vi>; using vpii = vector<pii>; using vvpii = vector<vpii>;
ifstream fin("wormsort.in");
ofstream fout("wormsort.out");

int N, M;
int* cows; 
bool* vis;
unordered_set <int> enctr_cows;
unordered_set <int> enctr_indexes;
struct connection {
	int width; 
	int x; 
	connection(int _x, int _width) { width = _width; x = _x;}
};
struct hole {
	vector<connection> dest; 
	hole() {};
};
hole* holes; 

void dfs(int pos, int in_width) {
	if (!vis[pos]) {
		vis[pos] = true;
		enctr_cows.insert(cows[pos]); 
		enctr_indexes.insert(pos);
		for (int i = 0; i < holes[pos].dest.size(); i++) {
			if (holes[pos].dest[i].width >= in_width) 
				dfs(holes[pos].dest[i].x, in_width);
		}
	}
}

bool check(int in_width) {
	fill(vis, vis + N, false);
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			enctr_cows.clear();
			enctr_indexes.clear();
			dfs(i, in_width);
			if (enctr_cows != enctr_indexes) return false;
		}
	}
	for (int i = 0; i < N; i++) {
		if (vis[i] == false && i != cows[i]) return false;
	}
	return true; 
}

int binsearch() {
	int low = 0; 
	int high = 1000000000;
	int sol = - 1; 
	while (low <= high) {
		int mid = (low + high) / 2; 
		if (check(mid)) {
			sol = mid; 
			low = mid + 1; 
		}
		else {
			high = mid - 1; 
		}
	}
	return sol; 
}

int main() {
	read >> N >> M; 
	holes = new hole[N]; 
	cows = new int[N]; 
	vis = new bool[N]; 
	for (int i = 0; i < N; i++) {
		int a; read >> a; a--;  cows[i] = a; 
	}
	bool not_sorted = false; 
	for (int i = 0; i < N; i++) if (i != cows[i]) not_sorted = true; 
	if (!not_sorted) { cout << -1 << endl; write << -1 << endl; return 1; }
	for (int i = 0; i < M; i++) {
		int a, b, width; read >> a >> b >> width; a--; b--; 
		holes[a].dest.pb(connection(b, width)); 
		holes[b].dest.pb(connection(a, width));
	}
	int ans = binsearch();
	cout << ans << endl; write << ans << endl; 
}
