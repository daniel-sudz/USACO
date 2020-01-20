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

set<int> all_barn_1_combinations; 

void calculate_combinations(int vol_tank_1, int vol_tank_2, int day, vector<int> buckets_barn1, vector<int> buckets_barn2) {
	if (day == 1 || day == 3) {
		for (int i = 0; i < buckets_barn1.size(); i++) {
			int bucket = buckets_barn1[i];
			vector<int> buckets_barn_one_copy = buckets_barn1;
			vector<int> buckets_barn_two_copy = buckets_barn2;
			int vol_tank_1_copy = vol_tank_1;
			int vol_tank_2_copy = vol_tank_2;
			buckets_barn_one_copy.erase(buckets_barn_one_copy.begin() + i);
			buckets_barn_two_copy.push_back(bucket);
			if (vol_tank_1_copy > bucket) {
				vol_tank_1_copy -= bucket;
				vol_tank_2_copy += bucket;
			}
			else {
				vol_tank_2_copy -= vol_tank_1;
				vol_tank_1_copy = 0;
			}
			calculate_combinations(vol_tank_1_copy, vol_tank_1_copy, day + 1, buckets_barn_one_copy, buckets_barn_two_copy);
		}
	}
	if (day == 2 || day == 4) {
		for (int i = 0; i < buckets_barn2.size(); i++) {
			int bucket = buckets_barn2[i];
			vector<int> buckets_barn_one_copy = buckets_barn1;
			vector<int> buckets_barn_two_copy = buckets_barn2;
			int vol_tank_1_copy = vol_tank_1;
			int vol_tank_2_copy = vol_tank_2;
			buckets_barn_two_copy.erase(buckets_barn_two_copy.begin() + i);
			buckets_barn_one_copy.push_back(bucket);
			if (vol_tank_2_copy > bucket) {
				vol_tank_2_copy -= bucket;
				vol_tank_1_copy += bucket;
			}
			else {
				vol_tank_1_copy -= vol_tank_2_copy;
				vol_tank_2_copy = 0;
			}
			if (day == 4) {
				all_barn_1_combinations.insert(vol_tank_1_copy);
			}
			else {
				calculate_combinations(vol_tank_1_copy, vol_tank_2_copy, day + 1, buckets_barn_one_copy, buckets_barn_two_copy);
			}
		}
	}
}

int main() {
	cout << "backforth" << endl;

	ofstream fout("backforth.out");
	ifstream fin("backforth.in");

	vector<int> buckets_barn_1; 
	vector<int> buckets_barn_2;

	for (int i = 0; i < 10; i++) {
		int bucket_vol; 
		fin >> bucket_vol;
		buckets_barn_1.push_back(bucket_vol);
	}
	for (int i = 0; i < 10; i++) {
		int bucket_vol;
		fin >> bucket_vol;
		buckets_barn_2.push_back(bucket_vol);
	}
	calculate_combinations(1000, 1000, 1, buckets_barn_1, buckets_barn_2);

	fout << all_barn_1_combinations.size() << endl;
}

