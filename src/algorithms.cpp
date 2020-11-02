#include <iostream>
#include <vector>

#include "algorithms.h"

using namespace std;

void algorithms::print_vector(vector<int> vec) {
	for (auto el : vec) {
		cout << el << ' ';
	}
	cout << endl;
}

void algorithms::insertion_sort(vector<int> &vec) {
	for (int i = 1; i < vec.size(); i++) {
		int a = vec[i];
		int j = i - 1;
		while (j > -1 && a < vec[j]) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = a;
	}
}