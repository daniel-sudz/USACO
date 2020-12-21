using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using ll = long long;

int N;
struct cord {
    int X;
    int Y;
};

bool sortX(cord pair1, cord pair2) {
    if (pair1.X < pair2.X) {
        return true; 
    }
    if (pair1.X > pair2.X) {
        return false;
    }
    if (pair1.Y < pair2.Y) {
        return true; 
    }
    return false; 
}

int main() {
    ofstream fout("moop.out");
    ifstream fin("moop.in");

    fin >> N;
    
    cord* points = new cord[N];  
    for (int i = 0; i < N; i++) {
        fin >> points[i].X >> points[i].Y; 
    }
    sort(points, points + N, sortX);

    int* minys = new int[N]; 
    int miny = points[0].Y; 
    for (int i = 0; i < N; i++) {
        miny = min(miny, points[i].Y); 
        minys[i] = miny; 
    }

    int* maxys = new int[N]; 
    int maxy = points[N - 1].Y; 
    for (int i = N - 1; i >= 0; i--) {
        maxy = max(maxy, points[i].Y); 
        maxys[i] = maxy; 
    }

    int sol = 1; 
    for (int i = 0; i < N - 1; i++) {
        if (minys[i] > maxys[i + 1]) {
            sol++; 
        }
    }
    fout << sol << endl; 
}

