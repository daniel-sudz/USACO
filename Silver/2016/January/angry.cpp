#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using vii = vector<vi>; using vpii = vector<pii>; using vvpii = vector<vpii>;
ifstream fin("angry.in");
ofstream fout("angry.out");

int N, K; 
ll* d; 

bool verify(int r) {
	int blasts = 1; 
	int lower = 0;
	int i = 0; 
	while (i < N) {
		if (d[i] - d[lower] <= 2*r) {
			i++; 
		}
		else {
			lower = i; 
			blasts++; 
		}
	}
	return blasts <= K; 
}


int main() {
	read >> N >> K;
	d = new ll[N]; 
	for (int i = 0; i < N; i++) read >> d[i]; 
	sort(d, d + N);

	ll low = 0; 
	ll high = 1000000000;
	ll sol = high;
	while (low <= high) {
		ll mid = (low + high) / 2; 
		if (verify(mid)) {
			high = mid - 1; 
			sol = min(sol, mid);
		}
		else {
			low = mid + 1; 
		}
	}
	cout << sol << endl; 
	write << sol << endl; 
}
