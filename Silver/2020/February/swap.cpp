using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using ll = long long;

// problem about exponentiation (log base 2)
// log base 2 of 10^9 runtime main algo
// base combo 10^5 * 10^2 = 10^7 runtime

int N; 
int M; 
int K; 

int* L; 
int* R; 

int* swap(int* toswap, int* combo) {
    int* res = new int[N]; 
    for (int i = 0; i < N; i++) {
        res[i] = toswap[combo[i]]; 
    }
    delete[] toswap; 
    return res; 
}

int main() {
    ofstream fout("swap.out");
    ifstream fin("swap.in");

    fin >> N >> M >> K; 
    L = new int[M]; 
    R = new int[M]; 

    for (int i = 0; i < M; i++) {
        int lin, rin; 
        fin >> lin >> rin; 
        L[i] = lin - 1;
        R[i] = rin - 1;
    }

    int* basecombo = new int[N]; 
    for (int i = 0; i < N; i++) {
        basecombo[i] = i; 
    }
    
    // fill in the base combo in 10^5 * 100 = 10^7
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < (R[i] - L[i])/2 + 1; j++) {
            int temp = basecombo[L[i] + j]; 
            basecombo[L[i] + j] = basecombo[R[i] - j]; 
            basecombo[R[i] - j] = temp;
        }
    }

    int* solution = new int[N];
    for (int i = 0; i < N; i++) {
        solution[i] = i;
    }
    solution = swap(solution, basecombo); 

    int* curcombo = new int[N]; 
    copy(solution, solution + N, curcombo); 
    int numswaps = 1;

    while (numswaps != K) {
        if (numswaps * 2 <= K) {
            solution = swap(solution, curcombo);
            curcombo = swap(curcombo, curcombo);
            numswaps *= 2; 
        }
        else if (K - numswaps != 1){ 
           copy(basecombo, basecombo + N, curcombo); 
           solution = swap(solution, curcombo);
           K = K - numswaps; 
           numswaps = 1; 
        }
        else {
            solution = swap(solution, basecombo);
            numswaps++; 
        }
    }


    for (int i = 0; i < N; i++) {
        fout << solution[i] + 1 << endl; 
    }
}
