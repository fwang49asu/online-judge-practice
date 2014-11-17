#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
	long long data[20][20];
	for(int i=0; i<20; ++i) {
		for(int k=0; k<20; ++k) {
			cin >> data[i][k];
		}
	}
	long curMax = 0;
	vector<long long> diagnal[39];
	vector<long long> antiDiagnal[39];
	int n = 20;
	for(int i=0; i<20; ++i) {
		for(int k=0; k<=i; ++k) {
			antiDiagnal[i].push_back(data[i-k][k]);
		}
	}
	for(int i=1; i<20; ++i) {
		for(int k=i; k<20; ++k) {
			antiDiagnal[19+i].push_back(data[n-k][k]);
		}
	}
	for(int i=0; i<20; ++i) {
		for(int k=0; (i+k) < 20; ++k) {
			diagnal[i].push_back(data[i+k][k]);
		}
	}
	for(int i=1; i<20; ++i) {
		for(int k=0; (i+k) < 20; ++k) {
			diagnal[19+i].push_back(data[k][i+k]);
		}
	}

	// row
	for(int i=0; i<20; ++i) {
		for(int k=0; k<n-4; ++k) {
			long temp = data[i][k] * data[i][k+1] * data[i][k+2] * data[i][k+3];
			if(curMax < temp) {
				curMax = temp;
			}
		}
	}

	// col
	for(int i=0; i<20; ++i) {
		for(int k=0; k<n-4; ++k) {
			long temp = data[k][i] * data[k+1][i] * data[k+2][i] * data[k+3][i];
			if(curMax < temp) {
				curMax = temp;
			}
		}
	}

	cout << curMax << endl;

	// diagnal
	for(int i=0; i<39; ++i) {
		if(diagnal[i].size() < 4) {
			continue;
		}
		for(int k=0; k<diagnal[i].size() - 4; ++k) {
			cout << i << " " << diagnal[i].size() << endl;
			long temp = diagnal[i][k] * diagnal[i][k+1] * diagnal[i][k+2] * diagnal[i][k+3];
			if(curMax < temp) {
				curMax = temp;
			}
		}
	}
	cout << curMax << endl;
	for(int i=0; i<39; ++i) {
		if(antiDiagnal[i].size() < 4) {
			continue;
		}
		for(int k=0; k<antiDiagnal[i].size() - 4; ++k) {
			long temp = antiDiagnal[i][k] * antiDiagnal[i][k+1] * antiDiagnal[i][k+2] * antiDiagnal[i][k+3];
			if(curMax < temp) {
				curMax = temp;
			}
		}
	}
	cout << curMax << endl;
	return 0;
}
