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
	cout << "revegetate" << endl;

	ofstream fout("revegetate.out");
	ifstream fin("revegetate.in");

	int N; 
	int M;

	fin >> N; 
	fin >> M; 

	map<int, vector<int>> fields;
	vector<vector<int>> cows;

	vector<int> solutions; 
	for (int i = 0; i < N +1 ; i++) {
		solutions.push_back(0);
	}

	for (int i = 0; i < M; i++) {
		int field1; 
		int field2; 

		fin >> field1; 
		fin >> field2;

		cows.push_back({ field1, field2 });
		if (fields.find(field1) == fields.end()) {
			fields[field1] = { i };
		}
		else {
			vector<int> curr_array = fields[field1];
			curr_array.push_back(i);
			fields[field1] = curr_array;
		}
		if (fields.find(field2) == fields.end()) {
			fields[field2] = { i };
		}
		else {
			vector<int> curr_array = fields[field2];
			curr_array.push_back(i);
			fields[field2] = curr_array;
		}
	}

	solutions[1] = 1; 
	for (int i = 2; i < N + 1; i++) {
		vector<int> cows_in_field = fields[i]; 
		set<int> number_in_use;
		vector<int> min_field;
		for (int b = 0; b < cows_in_field.size(); b++) {
			vector<int> ref_field = cows[cows_in_field[b]];
			for (int c = 0; c < ref_field.size(); c++) {
				number_in_use.insert(solutions[ref_field[c]]);
			}
		}
		for (auto it1 = number_in_use.begin(); it1 != number_in_use.end(); ++it1)
			if (*it1 != 0) {
				min_field.push_back(*it1);
			}
		if (find(min_field.begin(), min_field.end(), 1) == min_field.end()) {
			solutions[i] = 1;
		}
		else if (find(min_field.begin(), min_field.end(), 2) == min_field.end()) {
			solutions[i] = 2;
		}
		else if (find(min_field.begin(), min_field.end(), 3) == min_field.end()) {
			solutions[i] = 3;
		}
		else {
			solutions[i] = 4; 
		}
	}
	
	solutions.erase(solutions.begin());
	string return_solution = ""; 
	for (int i = 0; i < N; i++) {
		string read_num = to_string(solutions[i]);
		return_solution += read_num; 
	}
	
	fout << return_solution << endl;
}

