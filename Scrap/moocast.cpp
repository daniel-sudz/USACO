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

int N;
int* X; int* Y; int* P; int* DS;

bool reach(int x1, int x2, int y1, int y2, int p1, int p2) {
	int dis = abs(x1 - x2) * abs(x1 - x2);
	dis += abs(y1 - y2) * abs(y1 - y2);
	if (dis <= p1*p1 || dis <= p2*p2) return true; return false; 
}

int FIND(int pt) {
	int ptr = pt;
	while (DS[ptr] != -1) {
		ptr = DS[ptr];
	}
	while (DS[pt] != -1) {
		DS[pt] = ptr;
		pt = DS[pt];
	}
	return ptr;
}

void UNION(int p1, int p2) {
	if (p1 == p2) return; 
	int h1 = FIND(p1); int h2 = FIND(p2);
	if (h1 == h2) return; 
	DS[h1] = h2; 
};



int main() {
	read >> N; 
	X = new int[N]; Y = new int[N]; P = new int[N]; DS = new int[N]; 
	for (int i = 0; i < N; i++) {
		read >> X[i] >> Y[i] >> P[i]; 
	}
	fill(DS, DS + N, -1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (reach(X[i], X[j], Y[i], Y[j], P[i], P[j]) == true) {
				UNION(i, j); 
			}
		}
	}
	bool* vis = new bool[N] {}; 
	int best = 0; int cur = 1; 
	for (int i = 0; i < N; i++) {
		if (vis[i] == false) {
			int ptr = i; 
			while (DS[ptr] != -1) {
				vis[ptr] = true; ptr = DS[ptr]; cur++; 
			}
			best = max(best, cur); 
		}
	} 
	fout << best << endl; 
}
