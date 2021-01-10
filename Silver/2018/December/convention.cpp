#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using vii = vector<vi>; using vpii = vector<pii>; using vvpii = vector<vpii>;
ifstream fin("convention.in");
ofstream fout("convention.out");

int N, M, C; 
int* T;

// return index of largest index <= to value
int SEARCH(int n) {
	int low = 0;
	int high = N - 1;
	int ans = 0; 
	while (low <= high) {
		int mid = (low + high) / 2;
		if (T[mid] <= n) {
			low = mid + 1;
			ans = max(ans, mid); 
		}
		else if (high){
			high = mid - 1; 
		}
	}
	return ans;
}

bool validate(int t) {
	int i = 0; 
	int buses = 0; 
	while (i < N) {
		int load = min(SEARCH(T[i] + t) - i + 1, C);
		i += load; 
		buses++;
		if (buses > M) return false; 
	}
	return true; 
}



int main() {
	read >> N >> M >> C; 
	T = new int[N]; 
	for (int i = 0; i < N; i++) read >> T[i];
	sort(T, T + N); 
	int low = 0; 
	int high = 1000000000;
	int ans = high; 
	while(low <= high) {
		int mid = (low + high) / 2; 
		if (validate(mid)) {
			high = mid - 1;
			ans = min(ans, mid); 
		}
		else {
			low = mid + 1; 
		}
	}
	cout << ans;  write << ans;
}
