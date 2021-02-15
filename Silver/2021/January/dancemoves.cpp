#include <bits/stdc++.h>
#include <unordered_set>
#include <chrono>
#define pb push_back
#define read cin
#define write cout
#pragma warning(disable:6385)
using namespace std;
using ll=long long;using vi=vector<int>;using pii=pair<int,int>;using vii=vector<vi>;using vpii=vector<pii>;using vvpii=vector<vpii>; 
ifstream fin("dancemoves.in");
ofstream fout("dancemoves.out");

int N, K; 
vpii initial_permutation; 

struct one_cycle {
	int final_position = -1; 
	bool final = false; 
	unordered_set<int> *visited = new unordered_set<int>;
};

int main() {
	cin.tie(0), cout.sync_with_stdio(0);
	auto start = chrono::steady_clock::now();
	read >> N >> K; 
	for (int i = 0; i < K; i++) {
		int a, b; read >> a >> b; a--; b--; 
		initial_permutation.pb(make_pair(a,b));
	}
	// compute inital permuation
	one_cycle* perms = new one_cycle[N]; 
	int* result = new int[N]; 
	for (int i = 0; i < N; i++) result[i] = i; 
	for (int i = 0; i < K; i++) {
		pii swap = initial_permutation[i]; 
		perms[result[swap.first]].visited->insert(swap.second);
		perms[result[swap.second]].visited->insert(swap.first);
		int tmp = result[swap.first]; 
		result[swap.first] = result[swap.second];
		result[swap.second] = tmp; 

	}
	// compute final positions 
	for (int i = 0; i < N; i++) {
		perms[i].visited->insert(i); 
		perms[result[i]].final_position = i; 
	}
	// compute all positions reached
	for (int i = 0; i < N; i++) {
		unordered_set<int> vis = { i }; 
		int ref = perms[i].final_position; 
		while (true)  {
			if (perms[i].final) {
				break; 
			}
			if (perms[i].visited->size() == N) {
				break; 
			}
			if (perms[ref].final) {
				perms[i].visited->insert(begin(*perms[ref].visited), end(*perms[ref].visited)); 
				break; 
			}
			else if (vis.count(ref) != 0) {
				break; 
			}
			else if (vis.count(ref) == 0) {
				vis.insert(ref); 
				perms[i].visited->insert(begin(*perms[ref].visited), end(*perms[ref].visited));
				ref = perms[ref].final_position; 
			}
		}
		// all numbers in chain have same number of places visited
		for (const int& number : vis) {
			perms[number].visited = perms[i].visited; 
			perms[number].final = true;
		}
		perms[i].final = true; 
		write << perms[i].visited->size() << "\n"; 

	}
	auto end = chrono::steady_clock::now();
	auto millis_diff = ((end - start).count()) / 1000000;
	//cout << millis_diff << endl; 
}
