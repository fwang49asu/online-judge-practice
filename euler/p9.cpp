#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	vector<int> vec;
	for(int i=0; i<500; i++) {
		int t = i+1;
		vec.push_back(t*t);
	}
	for(int c = 333; c<500; ++c) {
		for(int a = 1; a<=c; ++a) {
			int b = 1000 - a - c;
			if(b > c || (vec[a-1] + vec[b-1] != vec[c-1])) {
				continue;
			}
			cout << a*b*c << endl;
			return 0;
		}
	}
	return 0;
}
