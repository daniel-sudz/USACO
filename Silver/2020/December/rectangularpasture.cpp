#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>; 
using pll = pair<ll, ll>; 

ifstream fin("debug.in");
#define read cin 
#define INPUT 2500

ll N;
ll ans = 1; 
ll ps[INPUT][INPUT] = {}; //prefix sum array
pair<ll, ll>* P; 

bool sortX(pi A, pi B) {
	return A.first < B.first; 
}

bool sortY(pi A, pi B) {
	return A.second < B.second;
}

int main() {

	read >> N; 
	P = new pll[N];
	for (int i = 0; i < N; i++) {
		read >> P[i].first; 
		read >> P[i].second;
	}
	//compress Y
	sort(P, P + N, sortY);
	for (int i = 0; i < N; i++) {
		P[i].second = i;
	}
	//compress X 
	sort(P, P + N, sortX); 
	for (int i = 0; i < N; i++) {
		P[i].first = i; 
	}
	// compute prefix sum array 
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			int add = 0;
			if (x == 0 && y != 0) {
				add += ps[x][y - 1];
			}
			else if (x != 0 && y == 0) {
				add += ps[x - 1][y];
			}
			else if (x != 0 && y != 0) {
				add += (ps[x - 1][y] + ps[x][y - 1] - ps[x - 1][y - 1]);
			}
			if (P[x].second == y) {
				add++;
			}
			ps[x][y] += add;
		}
	}
	// compute permutations
	for (ll x1 = 0; x1 < N; x1++) {
		for (ll x2 = x1; x2 < N; x2++) {
			ll y1, y2;
			y1 = P[x1].second; 
			y2 = P[x2].second; 
			ll maxy = max(y1, y2); 
			ll miny = min(y1, y2);
			ll full = 0, midown = 0, down = 0, up = 0; 
			if (x1 != 0 && x2 != 0) {
				full = ps[x2][N - 1] - ps[x1 - 1][N - 1];
				midown = ps[x2][maxy] - ps[x1 - 1][maxy]; 
				if (miny > 0) {
					down = ps[x2][miny - 1] - ps[x1 - 1][miny - 1];
				}
				up = full - midown; 
				ans += (down + 1)*(up + 1); 
			}
			if (x1 == 0 && x2 == 0) {
				ans += 1;
			}
			if (x1 == 0 && x2 != 0) {
				full = ps[x2][N - 1];
				midown = ps[x2][maxy];
				if (miny > 0) {
					down = ps[x2][miny - 1];
				}
				up = full - midown;
				ans += (down + 1) * (up + 1);
			}
		}
	}
	cout << ans << endl; 
}
