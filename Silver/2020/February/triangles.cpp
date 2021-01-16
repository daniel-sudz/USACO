#include <bits/stdc++.h>
#define pb push_back
#define read fin
#define write fout
#include <unordered_set>
#pragma warning(disable:6385)
using namespace std;
using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using vii = vector<vi>; using vpii = vector<pii>; using vvpii = vector<vpii>;
ifstream fin("triangles.in");
ofstream fout("triangles.out");

int N;
const ll MOD = 1000000000 + 7; 
const ll POS = 10000;
unordered_map<int, vi> XtoY; 
unordered_map<int, vi> YtoX; 
unordered_set<int> Xs; 
unordered_set<int> Ys;
map<pair<int, int>, int> diffs_horizontal;
map<pair<int, int>, int> diffs_vertical; 
vector<pii> points; 

int main() {
	read >> N;
	for (int i = 0; i < N; i++) {
		int x1, y1; read >> x1 >> y1; x1 += POS; y1 += POS; Xs.insert(x1); Ys.insert(y1); 
		points.pb(make_pair(x1, y1));
		XtoY[x1].pb(y1); YtoX[y1].pb(x1);
	}
	// CREATE DIFFS HORIZONTAL 
	for (auto i = Ys.begin(); i != Ys.end(); i++) {
		int y1 = *i; 
		vi& x_cords = YtoX[y1];
		sort(begin(x_cords), end(x_cords)); 
		int total = 0; for (int a : x_cords) total += a; 
		int left_sum = 0; int right_sum = total - x_cords[0] * x_cords.size(); 
		int left_count = 1; int right_count = x_cords.size() - 1; 
		for (int i = 0; i < x_cords.size(); i++) {
			if (i != 0) {
				int x_diff = x_cords[i] - x_cords[i - 1];
				right_sum -= x_diff * right_count;
				left_sum += x_diff * left_count;
				left_count++; right_count--;
			}
			diffs_horizontal[make_pair(y1, x_cords[i])] = right_sum + left_sum;
		}
	}
	// CREATE DIFFS VERTICAL 
	for (auto i = Xs.begin(); i != Xs.end(); i++) {
		int x1 = *i;
		vi& y_cords = XtoY[x1];
		sort(begin(y_cords), end(y_cords));
		int total = 0; for (int a : y_cords) total += a;
		int left_sum = 0; int right_sum = total - y_cords[0] * y_cords.size();
		int left_count = 1; int right_count = y_cords.size() - 1;
		for (int i = 0; i < y_cords.size(); i++) {
			if (i != 0) {
				int y_diff = y_cords[i] - y_cords[i - 1];
				right_sum -= y_diff * right_count;
				left_sum += y_diff * left_count;
				left_count++; right_count--;
			}
			diffs_vertical[make_pair(x1, y_cords[i])] = right_sum + left_sum;
		}
	}
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		int x1 = points[i].first; 
		int y1 = points[i].second; 
		ll vertical = diffs_vertical[make_pair(x1, y1)]; 
		ll horizontal = diffs_horizontal[make_pair(y1, x1)]; 
		sum += vertical * horizontal;
	}
	cout << sum % MOD << endl; write << sum % MOD << endl; 
}
