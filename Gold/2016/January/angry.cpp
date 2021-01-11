#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#pragma warning(disable:6385)
using namespace std;
using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using vii = vector<vi>; using vpii = vector<pii>; using vvpii = vector<vpii>;
ifstream fin("angry.in");
ofstream fout("angry.out");

ll N;
ll* X;
const ll range = 1000000000;

// movement = 0 -> intial setup
// movement = 1 -> blast left 
// movement = 2 -> blast right
// center initially indicates pos for setup while left/right blast indicate index
// center is doubles for intial setup to avoid floating point rounding errors
bool LEFTBLAST = false;
bool RIGHTBLAST = false;
void blast(ll center, ll diameter, int movement) {
	if (movement == 0) {
		ll i = 0;
		while (abs(center - 2 * X[i]) > diameter && i < N) {
			if (2 * X[i] > center) {
				return;
			}
			i++;
		}
		blast(i, diameter - 2, 1);
		while (abs(center - 2* X[i]) <= diameter && i < N) {
			i++;
		}
		blast(i - 1, diameter - 2, 2);
	}
	if (movement == 1 && diameter >= 0) {
		int centerint = center; 
		ll i = center;
		if (center == 0) LEFTBLAST = true;
		else {
			while (i >= 0 && abs(2 * (X[centerint] - X[i])) <= diameter) {
				i--;
			}
			if (abs(i - center) == 1) return;
			blast(i + 1, diameter - 2, 1);
		}
	}

	if (movement == 2 && diameter >= 0) {
		int centerint = center;
		ll i = center;
		if (center < N) {
			if (center == N - 1) RIGHTBLAST = true;
			else {
				while (i < N && abs(2 * (X[centerint] - X[i])) <= diameter) {
					i++;
				}
				if (abs(i - center) == 1) return;
				blast(i - 1, diameter - 2, 2);
			}
		}

	}

}
// make not whole cordinates work
// mid represents double its actual value to avoid floating point rounding
ll MINPOS, MAXPOS; 
bool verify(ll diameter) {
	ll low = MINPOS;
	ll high = 2 * MAXPOS;
	while (low <= high) {
		ll mid = (low + high) / 2;
		LEFTBLAST = false; RIGHTBLAST = false;
		blast(mid, diameter, 0);
		if (LEFTBLAST && RIGHTBLAST) return true;
		if (!LEFTBLAST && !RIGHTBLAST) return false;
		if (LEFTBLAST) {
			low = mid + 1;
		}
		if (RIGHTBLAST) {
			high = mid - 1;
		}
	}
	return false;
}

int main() {
	read >> N;
	X = new ll[N];
	for (int i = 0; i < N; i++) read >> X[i];
	sort(X, X + N);
	MINPOS = X[0]; MAXPOS = X[N - 1]; 
	ll low = 0;
	ll high = range;
	ll sol = range;
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
	if (sol % 2 == 1) {
		cout << sol / 2 << ".5" << endl;
		write << sol / 2 << ".5" << endl;
	}
	else {
		cout << sol / 2 << ".0" << endl; 
		write << sol / 2 << ".0" << endl; 
	}
	
}
