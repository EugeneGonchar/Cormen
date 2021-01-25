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

void merge(vector<int>& vec, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int> left(n1);
	vector<int> right(n2);
	for (int i = 0; i < n1; i++) {
		left[i] = vec[p + i];
	}
	for (int i = 0; i < n2; i++) {
		right[i] = vec[q + 1 + i];
	}
	int i = 0;
	int j = 0;
 	for (int k = p; k < r + 1; k++) {
		if (i < left.size() && (j >= right.size() || left[i] < right[j])) {
			vec[k] = left[i];
			i++;
		} else {
			vec[k] = right[j];
			j++;
		}
	}
}

void algorithms::merge_sort(vector<int>& vec, int p, int r) {
	if (p < r) {
		int q = (r + p) / 2;
		algorithms::merge_sort(vec, p, q);
		algorithms::merge_sort(vec, q + 1, r);
		merge(vec, p, q, r);
	}
}
