#include <bits/stdc++.h>


using namespace std;
using ll = long long;
using vi = vector<int>; 

int N; 
int F[100000];
int sol = 0; 

int main() {
    ifstream fin("debug.in");
    cin >> N;
    fill(begin(F), end(F), 0);

    for (int i = 0; i < N - 1; i++) {
        int a = 100000; int b = 100000; 
        cin >> a >> b;
        a--; b--;
        F[a] ++; F[b] ++;
    }

    for (int i = 0; i < N; i++) {
        int pow = F[i];
        int infec = 1;
        int moves = 1;
        if (i == 0) { pow++;}
        while (infec < pow) {
            infec *= 2;
            moves++;
        }
        if (i == 0) { moves--; }
        sol += moves;
    }
    cout << sol;
}
