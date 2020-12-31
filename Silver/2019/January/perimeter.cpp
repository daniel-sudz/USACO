#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll=long long;using vi=vector<int>;using pii=pair<int,int>;using vii=vector<vi>;using vpii=vector<pii>;using vvpii=vector<vpii>; 
ifstream fin("perimeter.in");ofstream fout("perimeter.out");

int N; 
vpii blobs; 
char T [1000][1000]; 
bool V[1000][1000]{};
vvpii components; 
vpii component;

void ffill(int x, int y) {
	if (!V[x][y] && x >= 0 && y >= 0 && x < N && y < N && T[x][y] == '#') {
		V[x][y] = true; 
		component.push_back(make_pair(x, y)); 
		ffill(x + 1, y); ffill(x - 1, y); ffill(x, y - 1); ffill(x, y + 1); 
	}
}

int main() {
	read >> N; 
	for (int y = 0; y < N; y++) { 
		for (int x = 0; x < N; x++) {
			read >> T[x][y]; 
		}
	}
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			component.clear(); 
			ffill(x, y); 
			if (component.size() > 0) components.pb(component); 
		}
	}
	for (int i = 0; i < components.size(); i++) {
		int curper = 0;
		for (int j = 0; j < components[i].size(); j++) {
			int x = components[i][j].first; int y = components[i][j].second;
			if (x == 0 || T[x - 1][y] == '.') curper++; 
			if (x == N - 1 || T[x + 1][y] == '.') curper++; 
			if (y == 0 || T[x][y - 1] == '.') curper++; 
			if (y == N - 1 || T[x][y + 1] == '.') curper++;  
		}
		blobs.pb(make_pair((int) components[i].size(), curper)); 
	}
	sort(begin(blobs), end(blobs), [](pii b1, pii b2) { return b1.first < b2.first;  });
	int P = blobs[blobs.size() - 1].second; int i = blobs.size() - 1; 
	while (i > 0 && blobs[i - 1] == blobs[i]) {
		P = min(P, blobs[i].second);
		i--;
	}
	write << blobs[blobs.size() -1].first << " " << P << endl; 
}
