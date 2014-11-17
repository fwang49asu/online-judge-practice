#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long max_N = 4000000;
	vector<long long> vec;
	vec.push_back(1L);
	vec.push_back(2L);

	long long n = 3;
	long long base[] = {1L, 2L};
	while(n < max_N) {
		vec.push_back(n);
		base[0] = base[1];
		base[1] = n;
		n = base[0] + base[1];
	}

	long long result = 0;
	for(long long x : vec) {
		if(x % 2 == 0) {
			result += x;
		}
	}
	cout << result << endl;

	return 0;
}
