#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isprime(long long n, vector<long long>& vec) {
	long long maxX = static_cast<long long>(sqrt(n)) + 1L;
	for(int i=0; i<vec.size() && vec[i] <= maxX; i++) {
		if(n % vec[i] == 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[]) {
	int maxSize = atoll(argv[1]);
	long long n = 2;
	vector<long long> vec;
	while(vec.size() < maxSize) {
		if(isprime(n, vec)) {
			vec.push_back(n);
		}
		++n;
	}
	cout << vec[maxSize - 1] << endl;
	return 0;
}
