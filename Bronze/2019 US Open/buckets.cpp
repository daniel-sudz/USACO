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
	cout << "BUCKETS" << endl;

	

	ofstream fout("buckets.out");
	ifstream fin("buckets.in");

	int bx; 
	int by; 
	int lx; 
	int ly;
	int rx; 
	int ry;

	for (int i = 0; i < 10; i++) {
		for (int b = 0; b < 10; b++) {
			auto read_char = ' ';
			fin >> read_char; 
			if (read_char == 'B') {
				bx = b;
				by = i;
			}
			if (read_char == 'L') {
				lx = b; 
				ly = i; 
			}
			if (read_char == 'R') {
				rx = b; 
				ry = i;
			}
		}
	}

	int x_diff = abs(bx - lx) ; 
	int y_diff = abs(by - ly) ;


	if (x_diff == 0) {
		if (rx == bx && ((ry < ly && ry > by) || (ry > ly && ry < by))) {
			fout << (y_diff + 1) << endl;
		}
		else {
			fout << (y_diff - 1) << endl;
		}
	}
	else if (y_diff == 0) {
		if (ry == by && ((rx < lx && rx > bx) || (rx > lx && rx < bx))) {
			fout << (x_diff + 1) << endl;
		}
		else {
			fout << (x_diff + y_diff - 1) << endl;
		}
	}
	else {
		fout << (x_diff + y_diff -1) << endl;
	}
	
}