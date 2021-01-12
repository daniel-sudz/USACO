#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using vii = vector<vi>; using vpii = vector<pii>; using vvpii = vector<vpii>;
ifstream fin("loan.in");
ofstream fout("loan.out");

ll N, K, M; 

ll give(ll G, ll X) {return max(((N - G) / X), M);}

ll check(ll X) {
	ll days = 0;
	ll given = 0; 
	while (given <= N) {
		if (give(given, X) <= M) {
			ll add = (N - given) / M; 
			if (add * M != (N - given)) add++; 
			days += add; 
			if (days > K) return false; break;
		}
		else {
			ll daysLeft = ((N - given) - (((N - given) / X) * X)) / give(given, X); 
			days += daysLeft; 
			given += daysLeft * give(given, X); 
		}
		given += give(given, X); 
		days++;  
		if (days > K) return false; 
	}
	return true; 
}

ll binsearch() {
	ll low = 1;
	ll high = N + 1;
	ll sol = 1; 
	while (low <= high) {
		ll mid = (low + high) / 2; 
		if (check(mid)) {
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
	read >> N >> K >> M; 
	write << binsearch() << endl;
	cout << binsearch() << endl;
}
