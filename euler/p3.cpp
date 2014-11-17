#include <cmath>
#include <iostream>

using namespace std;

inline bool isprime(long long n) {
	long long x = (long long)sqrt(n) + 1L;
	while(x > 1) {
		if(n % x == 0) {
			return false;
		}
		x--;
	}
	return true;
}

int main(int argc, char* argv[]) {
	long long n = atoll(argv[1]);
	long long x = (long long)sqrt(n) + 1L;
	while(!(n % x == 0 && isprime(x))) {
		x--;
	}
	cout << x << endl;
	return 0;
}

