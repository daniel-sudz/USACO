#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using vii = vector<vi>; using vpii = vector<pii>; using vvpii = vector<vpii>;
ifstream fin("berries.in");
ofstream fout("berries.out");

int N, K; 
multiset<int, greater<int>> orig_trees; 
int solution = 0; 

int main() {
	read >> N >> K;  
	for (int i = 0; i < N; i++) { int a; read >> a; orig_trees.insert(a); }
	for (int i = 1; i < 1000; i++) {
		multiset<int, greater<int>> trees = orig_trees; 
		int filled = 0; 
		while (filled < K / 2) {
			auto ref = trees.begin();
			int val = *ref; 
			if (val >= i) {
				trees.erase(ref);
				trees.insert(val - i);
				filled++; 
			}
			else break; 

		} 
		int sum = 0;
		if (filled == K / 2) {
			int filled = 0;
			while (filled < K / 2) {
				auto ref = trees.begin();
				int val = *ref;
				int take = min(i, val); 
				trees.erase(ref); 
				trees.insert(val - take);
				filled++; 
				sum += take;
			}
		}
		solution = max(solution, sum); 
	}
	cout << solution << endl; 
	write << solution << endl; 
}
