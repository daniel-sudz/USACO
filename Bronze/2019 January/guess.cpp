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
	cout << "guess" << endl;

	vector<string> all_animals[100];

	ofstream fout("guess.out");
	ifstream fin("guess.in");

	int N; 

	fin >> N; 

	for (int i = 0; i < N; i++) {
		string animal_name; 
		fin >> animal_name;

		int trait_num;  
		fin >> trait_num;
		
		for (int b = 0; b < trait_num; b++) {
			string given_trait; 
			fin >> given_trait;
			all_animals[i].push_back(given_trait);
		}
	}



	int max_traits_in_common = 0; 
	int current_traits_in_common = 0;
	for (int i = 0; i < N; i ++) {
		for (int b = i+1; b < 100; b++) {
			max_traits_in_common = max(max_traits_in_common, current_traits_in_common);
			current_traits_in_common = 0;
			for (int c = 0; c < all_animals[i].size(); c++) {
				for (int d = 0; d < all_animals[b].size(); d++) {
					if (all_animals[i][c] == all_animals[b][d]) {
						current_traits_in_common++;
					}
				}
			}
		}
	}

	fout << max_traits_in_common + 1 << endl; 
}

