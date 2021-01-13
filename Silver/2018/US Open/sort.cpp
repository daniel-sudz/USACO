#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using vii = vector<vi>; using vpii = vector<pii>; using vvpii = vector<vpii>;
ifstream fin("sort.in");
ofstream fout("sort.out");

int N; 
int* arry; 
int* sorted; 
int sol = 0; 

void brute_force() {
	bool sorted = false; 
	while (!sorted) {
		for (int i = 0; i < N; i++) { cout << arry[i] << " "; } cout << endl;
		sorted = true;
		sol++; 
		for (int i = 0; i < N - 1; i++) {
			if (arry[i + 1] < arry[i]) {
				int tmp = arry[i + 1]; 
				arry[i + 1] = arry[i]; 
				arry[i] = tmp; 
				sorted = false; 
			}
		}
		
	}
}

int binsearch(int val) {
	int low = 0; int high = N; int sol = 0; 
	while (low <= high) {
		int mid = (low + high) / 2; 
		if (sorted[mid] <= val) {
			sol = mid; 
			low = mid + 1; 
		}
		else {
			high = mid - 1; 
		}
	}
	return sol; 
}

int main() {
	read >> N; 
	arry = new int[N]; 
	sorted = new int[N]; 
	for (int i = 0; i < N; i++) { read >> arry[i]; sorted[i] = arry[i]; }
	sort(sorted, sorted + N); 
	for (int i = 0; i < N; i++) {
		sol = max(sol, i - binsearch(arry[i]));
	} sol++; 
	cout << sol << endl; write << sol << endl; 
}
