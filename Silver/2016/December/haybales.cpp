#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using vii = vector<vi>; using vpii = vector<pii>; using vvpii = vector<vpii>;
ifstream fin("haybales.in");
ofstream fout("haybales.out");

int N, Q;
int* bales;

int searchlow(int lowbound) {
	int low = 0; int high = N - 1; int sol = N;
	while (low <= high) {
		int mid = (low + high) / 2; 
		if (bales[mid] >= lowbound) {
			high = mid - 1; 
			sol = min(sol, mid);
		}
		else {
			low = mid + 1; 
		}
	}
	return sol; 
}


int searchhigh(int highbound) {
	int low = 0; int high = N - 1; int sol = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (bales[mid] <= highbound) {
			low = mid + 1; 
			sol = max(sol, mid);
		}
		else {
			high = mid - 1; 
		}
	}
	return sol;
}

int main() {
	read >> N >> Q; 
	bales = new int[N]; 
	for (int i = 0; i < N; i++) read >> bales[i]; 
	sort(bales, bales + N); 
	for (int i = 0; i < Q; i++) {
		int a, b; read >> a >> b; 
		int minval = min(a, b); int maxval = max(a, b); 
		write << searchhigh(maxval) - searchlow(minval) + 1 << endl; 
	}
}
