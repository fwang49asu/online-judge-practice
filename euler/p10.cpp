#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isprime(long long n, vector<long long>& vec) {
	long long maxX = static_cast<long long>(sqrt(n)) + 1L;
	for(int i=0; i<vec.size() && vec[i] < maxX; ++i) {
		if(n % vec[i] == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	vector<long long> vec;
	for(long long i=2L; i<2000000L; ++i) {
		if(isprime(i, vec)) {
			vec.push_back(i);
		}
	}
	long long result = 0;
	for(int i=0; i<vec.size(); ++i) {
		result += vec[i];
	}
	cout << result << endl;
	return 0;
}
