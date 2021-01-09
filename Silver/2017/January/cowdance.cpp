#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using vii = vector<vi>; using vpii = vector<pii>; using vvpii = vector<vpii>;
ifstream fin("cowdance.in");
ofstream fout("cowdance.out");

int N, T; 
int* d; 

bool validate(int k) {
	multiset<ll, less<ll>> performance; 
	ll ttotal = 0; 
	ll offset = 0; 
	int it = k;
	for (int i = 0; i < k; i++) {
		performance.insert(d[i]); 
	}
	while (performance.size() != 0) {
		const auto begin = performance.begin();
		ll lowest = *begin; 
		performance.erase(begin);
		ttotal += (lowest - offset);
		offset = lowest;
		if (it != N) {
			performance.insert(d[it] + offset);
			it++;
		}
	}
	return ttotal <= T; 
}

int main() {
	read >> N >> T; 
	d = new int[N]; 
	for (int i = 0; i < N; i++) read >> d[i];
	int sol = N;
	int low = 1;
	int high = N;
	while (low <= high) {
		int mid = (low + high) / 2; 
		if (validate(mid)) {
			high = mid - 1; 
			sol = mid; 
		}
		else {
			low = mid + 1; 
		}
	}
	cout << sol; write << sol;
}
