using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using ll = long long;

void update(int cow, int choice, int** favs, int* chosen, bool* ate, int& total) {
    chosen[favs[cow][choice]] = cow;
    if (ate[cow] == false) {
        total++;
    }
    ate[cow] = true; 
}

// resolve conflicts recursively
void resolve(int cow, int** favs, int* chosen, bool* ate, int& total) {
    if (chosen[favs[cow][0]] == -1) {
        update(cow, 0, favs, chosen, ate, total); 
    }
    else if (chosen[favs[cow][0]] < cow) {
        int problem = chosen[favs[cow][0]]; 
        update(cow, 0, favs, chosen, ate, total);
        resolve(problem, favs, chosen, ate, total); 

    }
    else if (chosen[favs[cow][1]] == -1) {
        update(cow, 1, favs, chosen, ate, total);
    }
    else if (chosen[favs[cow][1]] < cow) {
        int problem = chosen[favs[cow][1]];
        update(cow, 1, favs, chosen, ate, total);
        resolve(problem, favs, chosen, ate, total);
    }
    else {
        if (ate[cow] == true) {
            total--; 
        }
        ate[cow] = false; 
    }
}


int main() {
    ofstream fout("cereal.out");
    ifstream fin("cereal.in");

    int N;
    int M;
    fin >> N >> M;
    
    // read in fav cereals
    int** favs = new int* [N]; 
    for (int i = 0; i < N; i++) {
        int* cow = new int[2]; 
        fin >> cow[0] >> cow[1];
        favs[i] = cow; 
    }
    reverse(favs, favs + N); 

    // which cereal chosen by which cow, -1 for avaliable
    int* chosen = new int[M + 2]; 
    fill_n(chosen, M + 2, -1); 

    // if a cow has eaten or not
    bool* ate = new bool[N]; 
    fill_n(ate, N, false);

    int* results = new int[N]; 
    int total = 0; 

    // back loop
    for (int i = 0; i < N; i++) {
        resolve(i, favs, chosen, ate, total);
        results[i] = total; 
    }
    
    for (int i = N - 1; i >= 0; i--) {
        fout << results[i] << endl; 
    }
}

