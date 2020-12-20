using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using ll = long long; 

// check if distance d is possible config
bool walk(ll distance, int N, int M, vector<vector<ll>>& grass) {
    int interval = 0; 
    int cows_placed = 1;  
    ll pos = grass[0][0]; 
    while (interval < M) {
        // if able to place cow in current interval
        if (pos + distance <= grass[interval][1]) {
            cows_placed++; 
            if (pos + distance <= grass[interval][0]) {
                pos = grass[interval][0];
            }
            else {
                pos += distance;
            }
        }
        // jump interval
        else {
            interval++;
        }
        if (cows_placed >= N) {
            return true;
        }
    }
    return false; 
}

bool grass_sort(vector<ll> a, vector<ll>b) {
    return a[0] < b[0]; 
}

int main() {
    ofstream fout("socdist.out");
    ifstream fin("socdist.in");

    int N;
    int M;
    fin >> N >> M;

    // read input
    vector<vector<ll>> grass; 
    for (int i = 0; i < M; i ++) {
        ll start; 
        ll end; 
        fin >> start >> end; 
        vector<ll> set = { start, end }; 
        grass.push_back(set); 
    }
    sort(grass.begin(), grass.end(), grass_sort);
    // bin search over d
    ll best_combo = 0; 
    ll low = 1; 
    ll high = ll (1000000000000000000) / ll (N);
    ll mid = (low + high) / 2; 

    while (low <= high) {
        if (walk(mid, N, M, grass)) {
            best_combo = max(best_combo, mid); 
            low = mid + 1; 
        }
        else {
            high = mid - 1; 
        }
        mid = (low + high) / 2; 
    }

    fout << best_combo; 
}

