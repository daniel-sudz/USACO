#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>; 
ifstream fin("pairup.in");
ofstream fout("pairup.out");

int N; 
pii* combos;  

int main() {
	read >> N; 
	combos = new pii[N]; 
	for (int i = 0; i < N; i++) {
		read >> combos[i].first >> combos[i].second;
	}
	sort(combos, combos + N, [](pii c1, pii c2) {return c1.second < c2.second; });
	int left = 0; int right = N - 1; int sol = combos[left].second + combos[right].second; 
	while (left <= right) {
		if (combos[left].first > combos[right].first) {
			combos[left].first -= combos[right].first; combos[right].first = 0; 
			sol = max(sol, combos[left].second + combos[right].second); 
			right--; 
		}
		else if (combos[left].first == combos[right].first) {
			sol = max(sol, combos[left].second + combos[right].second);
			left++; right--; 
		}
		else {
			combos[right].first -= combos[left].first; combos[left].first = 0;
			sol = max(sol, combos[left].second + combos[right].second);
			left++;
		}
	}
	write << sol << endl; 
}
