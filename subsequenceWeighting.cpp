#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <conio.h>

using namespace std;

int main() {
	clock_t start = clock();

	ifstream infile;
	infile.open("inputs/swInput.txt");

	string line;
	getline(infile, line);

	// get number of test cases
	int T = atoi(line.c_str());
	int N;
	for (int i = 0; i < T; ++i) {
		getline(infile, line);
		N = atoi(line.c_str());

		// populate arrays for each test case
		vector<long int> x[2]; // x[0] = elements, x[1] = weights
		stringstream ss;
		for (int j = 0; j < 2; ++j) {
			getline(infile, line);
			ss.str(line);

			int t;
			while (ss.good() && x[j].size() < (unsigned int)N) {
				ss >> t;
				x[j].push_back(t);
			}
		}

		/** DP **/
		// base case
		if (N == 1) return x[1][0];

		long int maxWeight = 0;
		vector<long int> W(N, 0);
		W[0] = x[1][0];
		for (int n = 0; n < N; ++n) {
		// find previous element max
			long int prevWeight = 0;
			for (int m = 0; m < n; ++m) {
				if (x[0][m] < x[0][n] && W[m] > prevWeight) {
					prevWeight = W[m];
				}
			}

			W[n] = prevWeight + x[1][n];
			if (W[n] > maxWeight) maxWeight = W[n];
		}

		cout << maxWeight << endl;
	}

	// clean up and wait for input to close
	infile.close();

	clock_t end = clock();
	cout << "Runtime: " << double(end - start) << " ms\n";
	_getch();
	return 0;
}