#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <cmath>
#include <ctgmath>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	cout << "herding" << endl;


	ofstream fout("herding.out");
	ifstream fin("herding.in");

	int A;
	int B; 
	int C; 

	int minval;
	int maxval = 0;

	fin >> A;
	fin >> B;
	fin >> C; 

	if (abs(A - B) == 2 || abs(B - C) == 2) {
		minval = 1; 
	}
	else {
		minval = 2;
	}

	maxval = max(maxval, (C - B - 1));
	maxval = max(maxval, (B - A - 1));
	
	if (B - A == 1 && C - B == 1) {
		maxval = 0; 
		minval = 0;
	}

	fout << minval << endl;
	fout << maxval << endl;
}

