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


void find_solutions(int current_n, vector<int> *conveyers, set<int, greater<int>> &solutions_for_given_n) {
	vector<int> connections = conveyers[current_n];
	if (connections.size() == 0) {
		return;
	}
	for (int i = 0; i < connections.size(); i++) {
		solutions_for_given_n.insert(connections[i]);
		bool if_already_visited_node = solutions_for_given_n.find(connections[i]) == solutions_for_given_n.end();
		if (if_already_visited_node) {
			break;
		}
		else {
			find_solutions(connections[i], conveyers, solutions_for_given_n);
		}
	}
};

int main() {
	cout << "MILK FACTORY BRONZE" << endl;

	vector<int> conveyers[101] = {};

	ofstream fout("factory.out");
	ifstream fin("factory.in");
	int N;
	fin >> N;

	for (int i = 0; i < N; i++) {
		string currline;

		int conveyer1;
		int conveyer2;
		fin >> conveyer1;
		fin >> conveyer2;

		if (conveyers[conveyer2].size() == 0) {
			conveyers[conveyer2] = { conveyer1 };
		}
		else {
			vector<int> existing_connections = conveyers[conveyer2];
			existing_connections.push_back(conveyer1);
			conveyers[conveyer2] = { existing_connections };
		}
	}

	set<int, greater<int>> solutions_for_given_n;
	vector<int> all_solutions; 
	for (int i = 1; i < N + 1; i++) {
		solutions_for_given_n.clear();
		find_solutions(i, conveyers, solutions_for_given_n);
		if (solutions_for_given_n.size() == N - 1) {
			all_solutions.push_back(i);
		}
	}
	//find_solutions(2, conveyers, solutions_for_given_n);
	if (all_solutions.size() == 0) {
		fout << -1 << endl;
	}
	else {
		int min_solution = 10000000;
		for (int i = 0; i < all_solutions.size(); i++) {
			min_solution = min(min_solution, all_solutions[i]);
			fout << min_solution << endl;
		}
	}
	cout << "foo";
}

