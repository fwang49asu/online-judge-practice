#include <iostream>

using namespace std;

int triangleCount(long long n) {
	long long x = n / 2;
	int result = 0;
	while(x >= 1) {
		if(n % x == 0L) {
			++result;
		}
		--x;
	}
	return result;
}

int main() {
	/*
	long long result = 656100000000L;
	while(triangleCount(result) <= 500) {
		++result;
	}
	cout << result << endl;
	*/
	return 0;
}
